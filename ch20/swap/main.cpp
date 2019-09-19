//Utterly useless program that uses a function template
//      -- from _C++ for Lazy Programmers_

template <typename T>
void swap(T& arg1, T& arg2)
{
	T temp = arg2; arg2 = arg1; arg1 = temp;
}

int main ()
{
    int    I = 10  , J = 20  ;
    double M =  0.5, N =  1.5;

    swap (I, J);
    swap (M, N);
    //swap (I, N); //No: can't figure what T should be

    return 0;
}
