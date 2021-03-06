// Problem 1.cpp : Defines the entry point for the console application.
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include "Problem 1.h"

using namespace std;

void numExtenso(const int num, char* extenso)
{
    char numero[15] = "";

    const char unid[19][10] = { "um", "dois", "três", "quatro", "cinco", "seis",
                               "sete", "oito", "nove", "dez", "onze", "doze", "treze",
                               "quatorze", "quinze", "dezesseis", "dezessete",
                               "dezoito", "dezenove" };

    const char dezena[8][10] = { "vinte", "trinta", "quarenta", "cinquenta", "sessenta",
                                 "setenta", "oitenta", "noventa" };

    const char centena[9][13] = { "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos",
                                  "seiscentos", "setecentos", "oitocentos", "novecentos" };


    // Converte de inteiro para string
    sprintf(numero, "%d", num);

    // Se for zero ou string vazia retorna 'zero'
    if (!strcmp(numero, "0") || numero[0] == '\0')
    {
        strcpy(extenso, "zero");
        return;
    }

    // Limpa a string 'extenso'
    extenso[0] = '\0';

    // Armazena o número de dígitos
    int n_digito = strlen(numero);

    for (int i = 0; i < n_digito; i++)
    {
        // Leitura das centenas
        if (((n_digito - 1 - i) % 3 == 2) && (numero[i] != '0'))
        {
            // Se 'extenso' não está vazio, acrescenta o conectivo 'e'
            if (extenso[0] != '\0')
            {
                strcat(extenso, " e ");
            }

            // Se for 100 escreve 'cem'
            if (numero[i] == '1' && numero[i + 1] == '0' && numero[i + 2] == '0')
            {
                strcat(extenso, "cem");
                continue;
            }
            else
            {
                // Escreve o nome da centena
                strcat(extenso, centena[(numero[i] - 48) - 1]);
            }

        }

        // Leitura das dezenas entre 20 e 99
        if ((n_digito - 1 - i) % 3 == 1 && numero[i] != '0')
        {
            // Se dezena for entre 10 e 19, passa para o próximo IF
            if (numero[i] == '1')
            {
                continue;
            }
            else
            {
                // Se 'extenso' não está vazio, acrescenta o conectivo 'e'
                if (extenso[0] != '\0')
                {
                    strcat(extenso, " e ");
                }

                // Escreve o nome da dezena
                strcat(extenso, dezena[numero[i] - 50]);

                continue;
            }
        }

        // Leitura da unidades e das dezenas entre 10 e 19
        if ((n_digito - 1 - i) % 3 == 0)
        {
            // Se for dezena entre 10 e 19
            if (n_digito > 1 && numero[i - 1] == '1')
            {
                // Acrescenta o conectivo 'e'
                if (extenso[0] != '\0')
                {
                    strcat(extenso, " e ");
                }

                // Escreve o nome da dezena
                strcat(extenso, unid[(numero[i] - 48) + 9]);
            }
            else
            {
                // Se for unidade
                if (numero[i] != '0')
                {
                    // Acrescenta o conectivo 'e'
                    if (extenso[0] != '\0')
                    {
                        strcat(extenso, " e ");
                    }

                    // Escreve o nome da unidade
                    strcat(extenso, unid[numero[i] - 49]);
                }
            }
        }

        // Acrescenta o texto 'mil'
        if ((n_digito - i) == 4)
        {
            // Verifica se existe algum milhar
            for (int j = i; (j >= 0) && (i - j < 3); j--)
            {
                if (numero[j] != '0')
                {
                    strcat(extenso, " mil");
                    break;
                }
            }
        }

        // Acrescenta o texto 'milhão' ou 'milhões'
        if ((n_digito - i) == 7)
        {
            // Verifica se o número é do formato 001.XXX.XXX
            if ((numero[i] == '1') && (n_digito == 7 || (n_digito == 8 && numero[i - 1] == '0') ||
                (n_digito == 9 && numero[i - 1] == '0' && numero[i - 2] == '0')))
            {
                strcat(extenso, " milhão");
            }
            else
            {
                // Verifica se existe algum milhão
                for (int j = i; (j >= 0) && (i - j < 3); j--)
                {
                    if (numero[j] != '0')
                    {
                        strcat(extenso, " milhões");
                        break;
                    }
                }
            }
        }
    }
}
string convertAmount2Words(int m, int n) {

    char str1[100];
    char str2[100];
    numExtenso(m, str1);
    numExtenso(n, str2);
    string strf = "";
    char ext[200];
    
    strcat(ext, str1);
    if (m > 1)
    {
        strcat(ext, " reais ");
    }
    else
    {
        strcat(ext, " real ");
    }
    strcat(ext, str2);
    if (n > 1)
    {
        strcat(ext, " centavos ");
    }
    else
    {
        strcat(ext, " centavo ");
    }
    return ext;
}
int main()
{
	ofstream fout("OUTPUT1.TXT");

	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = convertAmount2Words(10234234, 987123);

	fout << result.c_str() << "\n";

	fout.close();
    printf("%s", result);
	return 0;
}


