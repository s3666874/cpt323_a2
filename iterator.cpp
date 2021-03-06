#include <iostream>
#include <iterator>

class MyIterator : public std::iterator<std::input_iterator_tag, int> {
        int* p;

        public:
                MyIterator(int* x) : p(x) {}

                MyIterator(const MyIterator& mit) : p(mit.p) {}

                MyIterator& operator++() {
                        ++p;
                        return *this;
                }

                MyIterator operator++(int) {
                        MyIterator tmp(*this);
                        operator++(); 
                        return tmp;
                }

                bool operator==(const MyIterator& rhs) {
                        return p==rhs.p;
                }

                bool operator!=(const MyIterator& rhs) {
                        return p!=rhs.p;
                }

                int& operator*() {
                        return *p;
                }
};

int main () {
        int numbers[] = {1,2,3,4,5};
        
        MyIterator from(numbers);
        MyIterator until(numbers+5);

        for (MyIterator it = from; it != until; it++)
                std::cout << *it << ' ';
                std::cout << '\n';

        return 0;
}