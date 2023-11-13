// 동적 크기 배열 구현

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class DynamicArray {
    T* data;
    size_t n;

public:
    // 배열 크기를 인자로 받는 생성자
    DynamicArray(int n) {
        this->n = n;
        data = new T[n];
    }

    // 복사 생성자
    DynamicArray(const DynamicArray<T>& other) {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++)
            data[i] = other[i];
    }

    // [] 연산자
    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    // at 함수
    T& at(int index) {
        if (index < n)
            return data[index];
        throw "Index out of range";
    }

    // 배열 크기 반환
    size_t size() const {
        return n;
    }

    // 소멸자
    ~DynamicArray() {
        delete[] data; // 메모리 릭 방지 (할당된 메모리 해제)
    }

    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    T* end() {
        return data + n;
    }

    const T* end() const {
        return data + n;
    }

    friend DynamicArray<T> operator+(const DynamicArray<T>& arr1, DynamicArray<T>& arr2) {
        DynamicArray<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    std::string toString(const std::string& sep = " ") {
        if (n == 0)
            return "";
        
        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str();
    }
};

struct Student {
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
    int nStudents;

    std::cout << "1반 학생 수를 입력하세요: ";
    std::cin >> nStudents;

    DynamicArray<Student> class1(nStudents);
    for (int i = 0; i < nStudents; i++) {
        std::string name;
        int standard;

        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        std::cin >> name >> standard;
        class1[i] = Student{ name, standard };
    }

    try {
        class1.at(nStudents) = Student{ "John", 8 };
    } catch (...) {
        std::cout << "예외 발생" << std::endl;
    }

    // 깊은 복사
    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성: " << class2.toString() << std::endl;

    // 두 학급을 합쳐서 새로운 큰 학급을 생성
    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.toString() << std::endl;

    return 0;
}