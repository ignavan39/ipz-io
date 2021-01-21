#include <iostream>
#include <fstream>
#include "ring_buffer/ring_buffer.h"
#include "ring_buffer/ring_buffer.cpp"
#include "queue/queue.h"
#include "queue/queue.cpp"

using namespace std;

RingBuffer<int> read_from_file(string file_name);

int main(int argc, char** argv)
{
   // try{
        RingBuffer<int> r = read_from_file("./input.txt");
        Queue<int> queue;
        int buff;
	    cout << r.getSize() << endl;
        for(auto it = r.begin();it != r.end();++it){
            queue.insert(*it);
        }   
        cout<<queue.size();
        for(auto it = queue.begin();it != queue.end();++it){
            cout<< *it <<endl;
        }

  /* }
   catch(string error){
     //   cout<< error;
    }catch(exception exception){
        cout<<exception.what();
    }*/
	return 0;
}

RingBuffer<int> read_from_file(string file_name){
    ifstream read_stream(file_name);
    int l_dot;
    int r_dot;
    if(!read_stream.is_open()){
        throw "error in open file";
    }
    int size;
    read_stream.seekg(0,ios::end);
    if(read_stream.tellg()==0){
        throw "empty file";
    }
    read_stream.seekg(0,ios::beg);

    read_stream >> size;
    read_stream >> r_dot;
    read_stream >> l_dot;
    cout<< size << endl;

    int buff_elem;
    RingBuffer<int> res(size);
    for(int i =0;i<size;i++){
        read_stream >> buff_elem;
        res.push(buff_elem);
    }
    read_stream.close();
    return *res;
}