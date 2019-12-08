#ifndef __VECTOR__
#define __VECTOR__

template <typename T>
class Vector {
	public:
		Vector() = default;
		Vector(int n,T v) : size(n) {
			data = new T[n];
		}
		Vector(Vector& v)
		{
			size = v.getsize();
			delete [] data;
			data = new T[v.getsize()];
			for(int i = 0;i < size;i++)
			{
				data[i] = v.getdata()[i];
			}
		}
		~Vector() {delete [] data;}
		int getsize() const {return size;};
		T *getdata() const {return data;}

		void push(T element) {

		}
	private:
		T *data = NULL;
		int size = 0;
};

#endif