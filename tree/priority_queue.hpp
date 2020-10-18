#pragma once
#include<vector>
#include<math.h>
#include<initializer_list>
#include<stdexcept>
/*
Written by @apurvk4 on 18/10/20
*/
enum type{Min,Max};
template<typename T,type T1>
class priority_queue{
    public:
        priority_queue(){
        }
        priority_queue(std::initializer_list<T> l){
            T res;
            bool f=false;
            for(T val : l){
                if(!f){res=val;f=true;continue;}
                if(T1==Min){
                    res=std::min(res,val);
                }else if(T1==Max){
                    res=std::max(res,val);
                }
            }
            this->insert(res);
            for(T val : l){
                if(val !=res){
                    this->insert(val);
                }
            }
        }
        void decrease_key(int index,const T & new_val){ // 1 based index
            if(index > _arr.size() || index <= 0){return;}
            if(T1==Min){
                if(_arr[index-1]> new_val){
                    _arr[index-1]=new_val;
                    for(int i=index-1;i>0;i=index){
                        int p=floor((i-1)/2);
                        if(_arr[p]> _arr[i]){
                            std::swap(_arr[p],_arr[i]);
                            index=p;
                        }else{break;}
                    }
                }else if(_arr[index-1]<new_val){
                    _arr[index-1]=new_val;
                    for(int i=index-1;i<_arr.size();i=index){
                        int left=2*i+1;
                        int right=2*i+2;
                        if(left < _arr.size() and right < _arr.size()){
                            T temp=std::min(std::min(_arr[left],_arr[right]),_arr[i]);
                            if(temp==_arr[left]){
                                std::swap(_arr[left],_arr[i]);
                                index=left;
                            }else if(temp==_arr[right]){
                                std::swap(_arr[i],_arr[right]);
                                index=right;
                            }else{return;}
                        }else if(left < _arr.size() and right >= _arr.size()){
                            if(_arr[left]<_arr[i]){
                                std::swap(_arr[left],_arr[i]);
                                index=left;
                            }else{return;}
                        }else{return;}
                    }
                }
            }else if(T1==Max){
                if(_arr[index-1]< new_val){
                    _arr[index-1]=new_val;
                    for(int i=index-1;i>0;i=index){
                        int p=floor((i-1)/2);
                        if(_arr[p]< _arr[i]){
                            std::swap(_arr[p],_arr[i]);
                            index=p;
                        }else{break;}
                    }
                }else if(_arr[index-1]>new_val){
                    _arr[index-1]=new_val;
                    for(int i=index-1;i<_arr.size();i=index){
                        int left=2*i+1;
                        int right=2*i+2;
                        if(left < _arr.size() and right < _arr.size()){
                            T temp=std::max(std::max(_arr[left],_arr[right]),_arr[i]);
                            if(temp==_arr[left]){
                                std::swap(_arr[left],_arr[i]);
                                index=left;
                            }else if(temp==_arr[right]){
                                std::swap(_arr[i],_arr[right]);
                                index=right;
                            }else{return;}
                        }else if(left < _arr.size() and right >= _arr.size()){
                            if(_arr[left]>_arr[i]){
                                std::swap(_arr[left],_arr[i]);
                                index=left;
                            }else{return;}
                        }else{return;}
                    }
                }
            }
        }
        const std::vector<T> get_HeapArray(){
            return _arr;
        }
        const T get_Top(){
            return _arr[0];
            } 
        T extract_Top(){
            if(_arr.size()==0){
                throw std::out_of_range("No elements in Heap");
            }
            T res=_arr[0];
            if(_arr.size()==1){
                _arr.pop_back();
                return res;
            }
            _arr[0]=_arr[_arr.size()-1];
            _arr.pop_back();
            if(_arr.size()==1){return res;}
            heapify(0);
            return res;
        }
        unsigned int size(){
            return _arr.size();
        }
        void insert(const T & val){
            _arr.push_back(val);
            if(T1==Min){
                for(int i=_arr.size()-1;i>0;i=floor((i-1)/2)){
                    if(_arr[floor((i-1)/2)]> _arr[i]){
                        std::swap(_arr[i],_arr[floor((i-1)/2)]);
                    }else{break;}
                }
            }else if(T1==Max){
                for(int i=_arr.size()-1;i>0;i=floor((i-1)/2)){
                    if(_arr[floor((i-1)/2)] < _arr[i]){
                        std::swap(_arr[i],_arr[floor((i-1)/2)]);
                    }else{break;}
                }
            }
        }
        void remove(const T & val){
            bool flag=false;
            int index=0;
            for(int i=0;i<_arr.size();i++){
                if(_arr[i]==val){
                    flag=true;
                    index=i;
                    break;
                }
            }
            if(flag){
                _arr[index]=_arr[_arr.size()-1];
                _arr.pop_back();
                heapify(index);
            } 
        }
        bool empty(){return _arr.size()==0;}
        std::vector<T> get_sortedList(){
                std::vector<T> out;
                while(!empty()){
                    out.push_back(extract_Top());
                }
                return out;
        }
    private:
        void heapify(int index){
                if(T1==Min){
                    if(_arr.size()==2){
                        if(_arr[0]>_arr[1]){std::swap(_arr[0],_arr[1]);return;}else{return;}
                    }
                    for(int i=index;i<_arr.size();i=index){
                        int left=2*i+1;
                        int right=2*i+2;
                        if(left<_arr.size() && right< _arr.size()){
                            T temp=std::min(std::min(_arr[index],_arr[left]),_arr[right]);
                            if(temp==_arr[left]){
                                std::swap(_arr[left],_arr[index]);
                                index=left;
                            }else if(temp==_arr[right]){
                                std::swap(_arr[right],_arr[index]);
                                index=right;
                            }else{break;}                   
                        }else if(left < _arr.size() && right >=_arr.size()){
                            T temp=std::min(_arr[index],_arr[left]);
                            if(temp==_arr[left]){
                                std::swap(_arr[left],_arr[index]);
                                index=left;
                            }else{break;} 
                        }else{break;}
                    }
                }else if(T1==Max){
                    if(_arr.size()==2){
                        if(_arr[0]<_arr[1]){std::swap(_arr[0],_arr[1]);return;}else{return;}
                    }
                    for(int i=index;i<_arr.size();i=index){
                        int left=2*i+1;
                        int right=2*i+2;
                        if(left<_arr.size() && right< _arr.size()){
                            T temp=std::max(std::max(_arr[index],_arr[left]),_arr[right]);
                            if(temp==_arr[left]){
                                std::swap(_arr[left],_arr[index]);
                                index=left;
                            }else if(temp==_arr[right]){
                                std::swap(_arr[right],_arr[index]);
                                index=right;
                            }else{break;}                   
                        }else if(left < _arr.size() && right >= _arr.size()){
                            T temp=std::max(_arr[index],_arr[left]);
                            if(temp==_arr[left]){
                                std::swap(_arr[left],_arr[index]);
                                index=left;
                            }else{break;}   
                        }else{break;}                     
                    }
                }
        }
        std::vector<T> _arr; 
};