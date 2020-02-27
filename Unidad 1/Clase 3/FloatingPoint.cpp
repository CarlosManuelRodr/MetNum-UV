#include <iostream>
#include <fstream>
using namespace std;

char Bits64[8];

void show_bits(char *bits)
{
	for(int nByte=0; nByte<8; nByte++)
	{
		for(int i=128; i>0; i/=2)
		{
			if(bits[nByte] & i) cout << 1;
			else cout << 0;
		}
	}
	cout << endl;
}

double bit64_to_double(char *bits)
{
	void* ptr;
	ptr = bits;
	return *static_cast<double*>(ptr);
}

int main()
{
    int bit;
    bool val;
    
    cout << "Metodos numericos UV: Numeros" << endl;
    cout << "=============================" << endl;
    cout << "1- Generar numeros flotantes aleatorios" << endl;
    cout << "2- Cambiar valores en un numero flotante" << endl;
    
    int option = 0;
    cin >> option;
    cout << endl;
    
    if (option == 1)
    {
        cout << "Introduce la cantidad de numeros aleatorios a generar: ";
        int generate;
        cin >> generate;
        cout << endl;
    
        fstream fs;
        fs.open ("numbers.dat", std::ios::out);
        
        for (unsigned i = 0; i<generate; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Bits64[j] = rand() % 256;
            }
            
            fs << std::to_string(bit64_to_double(Bits64)) << endl;
        }
        fs.close();
    }
    else if (option == 2)
    {
        for (int i = 0; i < 8; i++)
        {
            Bits64[i] = 0x00;
        }
    
        while (true)
        {
            cout << "Bits: ";
            show_bits(Bits64);
            cout << "Valor de double: ";
            cout << bit64_to_double(Bits64) << endl;
        
            cout << "Introduce bit (1 - 64): ";
            cin >> bit;
            bit--;
            cout << "Introduce valor (0 - 1): ";
            cin >> val;
            cout << endl;
        
            int wri = 0x80;
            wri >>= bit % 8;
        
            if (val)
                Bits64[bit / 8] |= wri;
            else
                Bits64[bit / 8] ^= wri;
        }
    }
    else
        cout << "Error: Instruccion no reconocida" << endl;
    
    return 0;
}