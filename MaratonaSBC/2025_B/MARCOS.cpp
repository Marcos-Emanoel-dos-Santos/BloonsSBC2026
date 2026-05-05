#include <iostream>
#include <vector>

using namespace std;

struct Ciclo{
    long long tamanho;
    vector<long long> giros_validos;
};

long long mdc(long long a, long long b) {
    while (b != 0) {
        long long resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

long long mmc(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    long long divisao = a / mdc(a, b);

    if (2000000000LL / divisao < b) return 2000000000LL; 
    return divisao * b;
}

vector<size_t> kmp_search(vector<int>& str, vector<int>& pat){
    vector<size_t> matches;

    // DEFINIR O LPS
    vector<size_t> LPS(pat.size(), 0);
    size_t i = 1;
    size_t len = 0;
    while(i < pat.size()){
        if(pat[i] == pat[len]){
            len++;
            LPS[i] = len;
            i++;
        }
        else if(len != 0){
            len = LPS[len-1];
        }
        else {
            i++;
        }
    }

    // ALGORITMO KMP
    i = 0;
    len = 0;
    while(i < str.size()){
        if(str[i] == pat[len]){
            i++; len++;

        }
        if(len == pat.size()){
            matches.push_back(i - len);
            len = LPS[len-1];
        }
        else if(LPS[len] != 0){
            len = LPS[len] - 1;

        } else {
            i++;
        }
    }

    return matches;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Ciclo> baralho;

    vector<int> config_init(N);
    vector<int> config_end(N);
    vector<int> config_pos(N);

    for(size_t i = 0; i < N; i++) cin >> config_init[i];
    for(size_t i = 0; i < N; i++) cin >> config_end[i];
    for(size_t i = 0; i < N; i++) cin >> config_pos[i];
    
    vector<bool> visited(N, false);
    size_t pos = 0;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            vector<int> cycle_A;
            vector<int> cycle_B;

            int curr = i;

            while(!visited[curr]){
                visited[curr] = true;
                cycle_A.push_back(config_init[curr]);
                cycle_B.push_back(config_end[curr]);
                curr = config_pos[curr] - 1;
            }
        
            vector<int> double_A = cycle_A;
            double_A.insert(double_A.end(), cycle_A.begin(), cycle_A.end()-1);
            
            vector<size_t> giros = kmp_search(double_A, cycle_B);
            if(giros.size() == 0){
                cout << "IMPOSSIVEL\n";
                return 0;
            }

            vector<long long> restos_ll;
            for(size_t g : giros) restos_ll.push_back((long long)g);
            
            baralho.push_back({(long long)cycle_A.size(), restos_ll});
        }
    }

    long long passo_atual = 1;
    vector<long long> candidatos_K = {0};

    for (Ciclo cic : baralho) {
        vector<long long> novos_candidatos;
        long long novo_passo = mmc(passo_atual, cic.tamanho);
        
        for (long long k : candidatos_K) {
            
            for (long long r : cic.giros_validos) {
                long long temp_k = k;
                
                for (long long pulo = 0; pulo < cic.tamanho; pulo++) {
                    
                    if (temp_k % cic.tamanho == r) {
                        novos_candidatos.push_back(temp_k);
                        break; // Alinhou! Pode parar de pular.
                    }
                    temp_k += passo_atual; // Dá o pulo gigante
                }
            }
        }
        
        if (novos_candidatos.empty()) {
            cout << "IMPOSSIVEL\n";
            return 0;
        }
            
        candidatos_K = novos_candidatos;
        passo_atual = novo_passo;
    }

    long long resposta_final = candidatos_K[0];
    for (long long k : candidatos_K) {
        if (k < resposta_final) resposta_final = k;
    }

    if (resposta_final > 1000000000LL) {
        cout << "DEMAIS\n";
    } else {
        cout << resposta_final << "\n";
    }


    return 0;
}
