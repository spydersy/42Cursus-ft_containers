#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V, class C, class A>
void allocator_test(_map<T, V, C, A> mp) {
    for (int i = 0, j = 10; i < 10; ++i, ++j) {
        mp.insert(_make_pair(i, j));
    }
}

int main() {

    exit(run_map_allocator_unit_test<int, int, std::less<int>, Alloc<_pair<const int, int> > >("using\ allocator", allocator_test));
}

// int main()
// {
//     // int, int, ,
//     _map<int, int, std::less<int>, Alloc<_pair<const int, int> > > mp;
//     std::cout << "AAA" << std::endl;
//     for (int i = 0, j = 10; i < 10; ++i, ++j) {
//         mp.insert(_make_pair(i, j));
//         std::cout << "__MAP__SIZE__ : " << mp.size() << std::endl;
//     }
//     return 0;
// }