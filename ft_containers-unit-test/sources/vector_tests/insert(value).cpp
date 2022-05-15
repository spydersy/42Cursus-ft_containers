#include "../system/system_methods.ipp"
#include "__service.ipp"

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		// if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

template <typename T>
std::vector<int> insert_test_1(std::vector<T> vector) {
    std::vector<int> v;
    std::cerr << "CHECK_SYS_00 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    vector.assign(26000000, 1);
        std::cerr << "CHECK_SYS_01 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    g_start1 = timer();
        std::cerr << "CHECK_SYS_02 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
        std::cerr << "CHECK_SYS_03 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    g_end1 = timer();
        std::cerr << "CHECK_SYS_04 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v.push_back(vector.size());
        std::cerr << "CHECK_SYS_05 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v.push_back(vector.capacity());
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;
    std::cerr << "CHECK_SYS_06 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v1.push_back(&(*k2));
        std::cerr << "CHECK_SYS_07 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v1.push_back(&(*k3));
        std::cerr << "CHECK_SYS_08 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v1.push_back(&(*k4));
        std::cerr << "CHECK_SYS_09 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
    	v.push_back(vv.size());
    	v.push_back(vv.capacity());
    }
        std::cerr << "CHECK_SYS_10 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    return v;
}

template <typename T>
std::vector<int> insert_test_1(_vector<T> vector) {
    std::vector<int> v;
    std::cerr << "CHECK_USR_00 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    vector.assign(26000000, 1);
        std::cerr << "CHECK_USR_01 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    g_start2 = timer();
        std::cerr << "CHECK_USR_02 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
        std::cerr << "CHECK_USR_03 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    g_end2 = timer();
        std::cerr << "CHECK_USR_04 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v.push_back(vector.size());
        std::cerr << "CHECK_USR_05 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v.push_back(vector.capacity());
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    _vector<A> vv;
    _vector<B*> v1;
    std::cerr << "CHECK_USR_06 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v1.push_back(&(*k2));
        std::cerr << "CHECK_USR_07 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v1.push_back(&(*k3));
        std::cerr << "CHECK_USR_08 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    v1.push_back(&(*k4));
        std::cerr << "CHECK_USR_09 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
    	v.push_back(vv.size());
    	v.push_back(vv.capacity());
    }
        std::cerr << "CHECK_USR_10 : [" << vector.size() << "][" << vector.capacity() << "]" << std::endl;
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("insert(value)", insert_test_1, insert_test_1));
}