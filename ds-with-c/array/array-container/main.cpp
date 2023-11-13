
// 빠르고 범용적인 데이터 저장 컨테이너 만들기

#include <array>
#include <iostream>
#include <type_traits>

template<typename ... Args>
// array에 저장할 원소의 타입을 결정하기 위해 std::common_type 템플릿 사용
// 함수 인자에 의존적이기 때문에 함수 반환형을 후행 리턴 타입으로 지정함.
auto bulidArray(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)> {
    using commonType = typename std::common_type<Args...>::type;

    return {std::forward<commonType>((Args&&)args)...};
}

int main() {
    auto data = bulidArray(1, 0u, 'a', 3.2f, false);

    for (auto i: data)
        std::cout << i << " ";
    
    std::cout << std::endl;
}