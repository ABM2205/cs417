
class mat
{
public:
    mat(){A=NULL;}
    ~mat(){}
    mat(int r, int c){row=r; col=c;
                    A=new double *[row];
                    for(int i=0; i<row; i++)
                    {
                        A[i]=new double[col];
                    }
                    for(int i=0; i<row; i++)
                    {
                        for(int j=0; j<col; j++)
                        {
                            A[i][j]=0.0;
                        }
                    }
            }
            int getrow(){return row;}
            int getcol(){return col;}
            void display()
            {
                for(int i=0; i<row; i++)
                {
                    for(int j=0; j<col; j++)
                    {
                        cout<<setw(8)<<A[i][j];
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
        void ident(){
                    if(col==1){A[0][0]=1.0;}
                    else{
                    for(int i=0; i<row; i++)
                    A[i][i]=1.0;
                    }
                }
        void random_mat(double m)
        {   double sum=0.0;
            double r;
            default_random_engine gen(time(NULL));
            uniform_real_distribution<double> rdist(-1*m, m);
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    r=rdist(gen);
                    A[i][j]=r;
                    sum = sum+abs(r);
                }
                A[i][i]=sum;
                sum=0.0;
            }
        }
private:
    int row;
    int col;
    double ** A;
};