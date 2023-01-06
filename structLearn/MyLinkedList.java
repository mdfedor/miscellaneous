package structLearn;
import java.util.NoSuchElementException;

public class MyLinkedList<E>{

    private static class Node<E>{
        E val;
        Node<E> next;
        Node<E> prev;
        Node(E val){this.val=val;}
    }

    private final Node<E> head,tail;
    private int size;

    public MyLinkedList(){
        this.head=new Node<>(null);
        this.tail=new Node<>(null);
        head.next=tail;
        tail.prev=head;
        this.size=0;
    }

    public void addFirst(E e){
        Node<E> newNode=new Node<>(e);
        if(size==0){
            head.next=newNode;
            newNode.next=tail;
            newNode.prev=head;
            tail.prev=newNode;
        }else{
            Node<E>tmp=head.next;
            head.next=newNode;
            newNode.next=tmp;
            newNode.prev=head;
            tmp.prev=newNode;
        }
        size++;
    }

    public void addLast(E e){
        Node<E> newNode=new Node<>(e);
        if(size==0){
            head.next=newNode;
            newNode.next=tail;
            newNode.prev=head;
            tail.prev=newNode;
        }else{
            Node<E> tmp=tail.prev;
            tmp.next=newNode;
            newNode.next=tail;
            tail.prev=newNode;
            newNode.prev=tmp;
        }
        size++;
    }

    public void add(int index,E element){
        checkPositionIndex(index);
        if(isEmpty()){
            addFirst(element);
            return;
        }
        Node<E>curr=getNode(index);//获取到index位置的节点 add的时候是新节点插入到index位置,所以当前位置的节点会后移
        Node<E>prev=curr.prev;

        Node<E>newNode=new Node<>(element);
        newNode.next=curr;
        newNode.prev=prev;
        prev.next=newNode;
        curr.prev=newNode;
        size++;
    }

    public E removeFirst(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        Node<E> FirstNode=head.next;
        Node<E> tmp=FirstNode.next;

        head.next=tmp;
        tmp.prev=head;
        E delVal=FirstNode.val;
        FirstNode=null;
        size--;
        return delVal;
    }

    public E removeLast(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        Node<E> LastNode=tail.prev;
        Node<E> tmp=LastNode.prev;

        E delVal=LastNode.val;

        tmp.next=LastNode.next;
        tail.prev=tmp;
        LastNode=null;
        size--;
        return delVal;
    }

    public E remove(int index){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        checkElementIndex(index);
        // 这里找到的是要删除的元素
        Node<E> curr=getNode(index);
        E delVal=curr.val;

        Node<E> prev=curr.prev;

        prev.next=curr.next;
        curr.next.prev=prev;
        curr=null;
        size--;
        return delVal;
    }

    public E getFirst(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        return head.next.val;
    }

    public E getLast(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        return tail.prev.val;
    }

    public E get(int index){
        checkElementIndex(index);
        return getNode(index).val;
    }

    public E set(int index,E element){
        checkElementIndex(index);
        Node<E>curr=getNode(index);
        E val=curr.val;
        curr.val=element;
        return val;
    }


    // 获取index位置的节点
    public Node<E> getNode(int index){
        // checkElementIndex(index);
        Node<E>tmp=null;
        if(index>=size/2){
           //从后半部分找
           tmp=tail;
           for(int i=size-1;i>=index;i--){
                tmp=tmp.prev;
           }
        }else{
            //前半部分找
            tmp=head;
            for(int i=0;i<=index;i++){
                tmp=tmp.next;
            }
        }
        return tmp;
    }

    public void print(){
        Node<E>tmp=head;
        for(int i=0;i<size;i++){
            tmp=tmp.next;
            System.out.print(tmp.val+" ");
        }
        System.out.println();
    }

    public int size(){return size;}

    public boolean isEmpty(){return size==0;}

    private boolean isElementIndex(int index){return index>=0&&index<size;}

    private boolean isPositionIndex(int index){return index>=0&&index<=size;}

    private void checkElementIndex(int index){
        if(!isElementIndex(index))
            throw new IndexOutOfBoundsException("Index: "+index+", size: "+size);
    }

    private void checkPositionIndex(int index){
        if(!isPositionIndex(index))
            throw new IndexOutOfBoundsException("Index: "+index+", size: "+size);
    }


    public static void main(String[] args) {
        MyLinkedList<Integer> mls=new MyLinkedList<>();
        mls.addFirst(111);
        mls.addLast(222);
        mls.addLast(333);
        mls.addLast(444);
        mls.print();
        mls.add(0, 6666);
        mls.print();
        mls.add(1, 7777);
        mls.print();
        mls.add(4,9999);
        mls.print();
        mls.add(7, 22222);
        mls.print();
        mls.removeFirst();
        mls.print();
        mls.removeLast();
        mls.print();
        mls.remove(5);
        mls.print();
        mls.remove(2);
        mls.print();
        mls.set(0,777888999);
        mls.print();
        System.out.println(mls.get(2));
    }










}