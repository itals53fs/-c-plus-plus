//  ________________________________________________________________________________________
// |                             A       ____   ___     ___                                 |
// |                             /\     |      |    \  /                                    |
// |                            /  \    |_E__  |     | \___                                 |
// |                           /----\   |      |     |    S\                                |
// |                          /      \  |____  |__D_/  ____/                                |
// |________________________________________________________________________________________|
#include "iostream"
using namespace std;

int main()
{
	int i, j,in1,in2,se1,se2;
    const char ESC=27;
    char q;
    cout<<"Escolha o tamanho da matriz, no formato I,J"<<endl;
    cin>>in1>>q>>in2;
    cout<<"Escolha a primeira celula a ser exitada, no formato I,J"<<endl;
    cin>>se1>>q>>se2;
    se1-=1;
    se2-=1;
    int A[in1][in2], B[in1][in2];

	for(int i2 = 0; i2 < in1; i2++) //escrevendo a matriz e inicializando as celulas
	{
		cout << "\n";
		for(int j2 = 0; j2 < in2; j2++)
		{
			A[i2][j2] = 0;
			B[i2][j2]=0;
			if(i2 == se1 && j2 == se2)
			{
				A[i2][j2] = 2;
				B[i2][j2]=2;
			}
			cout << A[i2][j2] << "\t";
		}
	}
	cout << "\nAperte qualquer tecla + ENTER para iniciar" << endl;
	cin >> q;
	system("clear");
	do
	{
				for(i = 0; i <in1 ; i++) //lendo as linhas das matrizes
				{
					cout << "\n\t";
					for(j = 0; j < in2; j++) //lendo as colunas das matrizes
					{
						switch (A[i][j]) //comparando as duas matrizes e modificando as celulas
						{
						case 0:
							if(((A[i-1][j]==2)&&((i-1)!=(in1-in1-1))) || ((A[i + 1][j] == 2)&&((i+1)!=(in1+1))) || ((A[i][j - 1] == 2)&&((j-1)!=(in2-in2-1))) || ((A[i][j + 1] == 2)&&((j+1)!=(in2))))//expressão logica para implantar as regras
							{
								B[i][j] = 2;
							}
							break;
						case 1:
							B[i][j] = 0;
							break;
						case 2:
							B[i][j] = 1;
							break;
						}
						cout << B[i][j] << "\t";//escrevendo a matriz resultante
					}
				}
        for(int h=0;h<in1;h++) //atualizando primeira matriz
        {
            for(int k=0;k<in2;k++)
            {
                A[h][k]=B[h][k];
            }
        }
		cout << "\n\n\nAperte C + ENTER para pular para ao proximo tempo,\n ESC + ENTER para parar ou\n X + ENTER para excitar uma celula " << endl;
		cin >> q;
		if (q=='x')
        {
            int pp,gg;
            char h;
            cout<<"Digite a célula que será exitada, no formato I,J"<<endl;
            cin>>pp>>h>>gg;
            pp-=1;
            gg-=1;
            B[pp][gg]=2;
            cout<<"Digite C + ENTER para continuar ou ESC + ENTER  para sair"<<endl;
            cin>>q;
        }
		system("clear");
	}while ((q!=ESC)&&(q=='c'));
}
