#include "BitArray.h"

using namespace std;

    BitArray::BitArray(size_t capacity) : capacity_(((capacity/8) + 1)* 8), size_(capacity),
                                pointer_((char*)calloc((capacity / 8)  + 1, sizeof(char))){};
    void BitArray::push_back(const bool& flag){

        if (++size_ > capacity_){
            capacity_ *= 2;
            pointer_ = (char*)realloc(pointer_, (capacity_ / 8)*sizeof(char));
        }
        size_t char_position = size_ / 8, bit_position = size_ % 8;
        if (flag){
            pointer_[char_position] |= (1 << bit_position); //записываем 1 в нужный бит
        }
        else {
            pointer_[char_position] &= ~(1 << bit_position); //записываем 0 в нужный бит
        }
        size_++;
    }
    bool BitArray::at(const int& n){
        if (n < 0 ){
            throw invalid_argument("index is less than zero");
        }
        else {
            if (n > size_){
                throw invalid_argument("index is more than the number of elements");
            }
        }
        size_t char_position = n / 8, bit_position = n % 8;
        return (bool((1 << bit_position) & pointer_[char_position]));
    }

    void BitArray::assign(const int& to, const bool& value){
        if (to < 0 ){
            throw invalid_argument("index is lower than zero");
        }
        else {
            if (to > size_){
                throw invalid_argument("index is greater than the number of elements");
            }
        }
        size_t char_position = to / 8, bit_position = to % 8;
        if (value){
            pointer_[char_position] |= (1 << bit_position); //записываем 1 в нужный бит
        }
        else {
            pointer_[char_position] &= ~(1 << bit_position); //записываем 0 в нужный бит
        }
    }

    size_t BitArray::length(){
        return size_;
    }
    BitArray::~BitArray(){
        free(pointer_);
    }


void TestAll(){
    BitArray check_true(10);
    check_true.assign(7, true);
    assert(check_true.at(7));

    check_true.assign(7, false);
    assert(!check_true.at(7));

    BitArray check_false(13);
    check_false.assign(11, false);
    assert(!check_false.at(11));

    BitArray check_push_back(1);
    check_push_back.push_back(true);
    assert(check_push_back.at(2));
    check_push_back.push_back(false);
    assert(!check_push_back.at(3));
    assert(check_push_back.length());
}
