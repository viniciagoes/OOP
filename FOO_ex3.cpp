    #include <iostream>
    #include <set>
    #include <vector>

    using namespace :: std;

    int main() {
        int N, B, Nota;

      //vetor auxiliar de notas para insercao no multiset
        vector <int> Notas;

      //multiset para operações
        multiset <int> BateriadeNotas;
        multiset <int> :: iterator comeco;

        while(cin >> N){
            long long int Soma=0;
            cin >> B;

      //for para insercao no vetor
            for(int i=0;i<N;i++){
                cin >> Nota;
                Notas.push_back(Nota);
            }

      //Inserir a bateria de notas regida pelo B
            for(int i=0;i<B;i++){
                BateriadeNotas.insert(Notas[i]);
            }
      //adicionar e fazer a primeira soma uma vez
            for(comeco=++BateriadeNotas.begin();comeco !=--BateriadeNotas.end();comeco++)
                Soma+= *comeco;

      //for para andar no vetor fazendo as diferentes baterias e realizando a soma no multiset
            for(int i=0;i<N-B;i++){
                BateriadeNotas.erase(BateriadeNotas.lower_bound(Notas[i]));
                BateriadeNotas.insert(Notas[B+i]);
                for(comeco= ++BateriadeNotas.begin();comeco !=--BateriadeNotas.end();comeco++)
                    Soma+= *comeco;
            }
            cout << Soma << endl;

            BateriadeNotas.clear();
            Notas.clear();
        }

        return 0;
    }