package structLearn;

import java.util.NoSuchElementException;

public class MyArrayList<E>{
    private E[] data;
    //当前数组中元素个数
    private int size;
    private static final int INIT_CAP=1;
    public MyArrayList(){this(INIT_CAP);}
    public MyArrayList(int initCapacity){   
        data=(E[]) new Object[initCapacity];
        size=0;
    }

    public void addLast(E e){
        if(data.length==size){
            resize(data.length*2);
        }
        data[size]=e;
        size++;
    }

    public void add(int index,E element){
        checkPositionIndex(index);
        if(data.length==size){
            resize(data.length*2);
        }
        System.arraycopy(data, index, data, index+1, size-index);
        data[index]=element;
        size++;
    }

    public E removeLast(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        if(size<data.length/4){
            resize(data.length/2);
        }
        E deleteVal=data[size-1];
        data[size-1]=null;
        size--;
        return deleteVal;
    }

    public E remove(int index){
        checkElementIndex(index);
        System.arraycopy(data, index+1, data, index, size-index-1);
        E delVal=data[index];
        data[size-1]=null;
        size--;
        return delVal;
    }

    public E get(int index){
        checkElementIndex(index);
        return data[index];
    }

    public E set(int index,E element){
        checkElementIndex(index);
        E oldVal=data[index];
        data[index]=element;
        return oldVal;
    }

    public int size(){return size;}

    public boolean isEmpty(){return size==0;}


    public void print(){
        if(!isEmpty()){
            for(int i=0;i<size;i++){
                System.out.print(data[i]+"  ");
            }
            System.out.println();
        }
    }

    private boolean isElementIndex(int index){
        return index>=0 && index<size;
    }

    // add
    private boolean isPositionIndex(int index){
        return index>=0&&index<=size;
    }

    private void checkElementIndex(int index){
        if(!isElementIndex(index))
            throw new IndexOutOfBoundsException("Index: "+index+", size: "+size);
    }

    private void checkPositionIndex(int index){
        if(!isPositionIndex(index))
            throw new IndexOutOfBoundsException("Index: "+index+", size: "+size);

    }

    private void resize(int newCap){
        E[] temp=(E[]) new Object[newCap];
        System.arraycopy(data, 0, temp, 0, size);
        data=temp;
    }


    public static void main(String[] args) {
        MyArrayList<Integer> mlt=new MyArrayList<>();
        mlt.addLast(1);
        mlt.addLast(2);
        mlt.addLast(3);
        mlt.addLast(4);
        mlt.add(2, 666);
        mlt.print();
        mlt.remove(1);
        mlt.print();
        mlt.removeLast();
        mlt.print();
        mlt.set(0,777);
        mlt.print();
    }



}