//如果类不在头文件中声明的话，就可以只在头文件中include这个cpp，然后这个类的所有部分就都在这个cpp里了，比较完整。
class Compute {
public:
	int x;
	int y;
	Compute::Compute(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int Compute::myAdd(int a, int b) {
		return a + b;
	}

	int Compute::mySub(int a, int b) {
		return a - b;
	}
};

