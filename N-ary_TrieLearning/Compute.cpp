//����಻��ͷ�ļ��������Ļ����Ϳ���ֻ��ͷ�ļ���include���cpp��Ȼ�����������в��־Ͷ������cpp���ˣ��Ƚ�������
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

