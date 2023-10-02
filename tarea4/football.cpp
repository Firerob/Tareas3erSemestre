/*
Autor: Daniel Felipe Moncada Tello
username: chaufelipe
UVa: 10194 Football (aka Soccer)
    
    
    Analisis de complejidad:
    el algoritmo tiene whiles anidados, un ciclo externo que se ejecuta n veces
    en cada iteración, el ciclo lee los datos del partido. 
    el otro ciclo que ejecuta n veces en el peor caso. En cada iteración, el ciclo 
    busca al equipo correspondiente en el vector.

    La complejidad temporal del algoritmo seria de O(n^2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Fotball{

    string teamName;
    int pointsEarned, gamesPlayed, wins, ties, losses, goalDiff, goalScored, goalAgainst;

    public:
        Fotball();
        Fotball(string);
        string getNombreTeam();
        void setGamesPlayed();
        void setWins();
        void setTies();
        void setLosses();
        void setGoal(int, int);
        void printResult();

        bool operator<(const Fotball &team);
};


Fotball::Fotball(string equipoNombre){
    teamName = equipoNombre;
    pointsEarned = 0;
    gamesPlayed = 0;
    wins = 0;
    ties = 0;
    losses = 0;
    goalDiff = 0;
    goalScored = 0;
    goalAgainst = 0;
}

string Fotball::getNombreTeam(){
    return teamName;
}

void Fotball::setGamesPlayed(){
    gamesPlayed = gamesPlayed + 1;
}

void Fotball::setWins(){
    wins = wins + 1;
    pointsEarned = pointsEarned + 3;
}

void Fotball::setTies(){
    ties = ties + 1;
    pointsEarned = pointsEarned + 1;
}

void Fotball::setLosses(){
    losses = losses + 1;
}


void Fotball::setGoal(int golesFavor, int golesContra){
    goalScored = goalScored + golesFavor;
    goalAgainst = goalAgainst + golesContra;
    goalDiff = (golesFavor - golesContra) + goalDiff;
}


void Fotball::printResult(){
    cout << teamName << " " << pointsEarned << "p, " << gamesPlayed << 
    "g (" << wins << "-" << ties << "-" << losses << "), " << goalDiff << "gd (" << 
    goalScored << "-" << goalAgainst << ")" << endl;
}


bool Fotball::operator<(const Fotball &team){
    bool ans;
    if(pointsEarned == team.pointsEarned){
        ans = wins > team.wins;
        if(wins == team.wins){
            ans = goalDiff > team.goalDiff;
            if(goalDiff == team.goalDiff){
                ans = goalScored > team.goalScored;
                if(goalScored == team.goalScored){
                    ans = gamesPlayed < team.gamesPlayed;
                    if(gamesPlayed == team.gamesPlayed){
                        ans = teamName < team.teamName;
                    }
                }
            }
        }
    }
    else{
        ans = pointsEarned > team.pointsEarned;
    }

    return ans;
}


int convertidorStringEntero(string goles){
    int numero;

    if(goles.size() == 2){
        numero = ((goles[0] - '0') * 10) + (goles[1] - '0');
    }
    else if(goles.size() == 1){
        numero = goles[0] - '0';
    }

    return numero;
}

int main(){
    int nTorneos, totalEquipos, nPartidos;
    string torneoName, equiposName, resultPartidos;
    bool saltoLinea = false;

    cin >> nTorneos;
    cin.ignore();
    while(nTorneos > 0){
        if(saltoLinea == true){
            cout << endl;
        }
        saltoLinea = true;

        getline(cin, torneoName);

        vector<Fotball>vecEquipos;

        cin >> totalEquipos;
        cin.ignore();
        while(totalEquipos > 0){
            getline(cin, equiposName);
            vecEquipos.push_back(Fotball(equiposName));

            --totalEquipos;
        }
        cin >> nPartidos;
        cin.ignore();
        while(nPartidos > 0){
            getline(cin, resultPartidos);
            
            string primerTeam, segundoTeam, gol1, gol2;
            int golesTeam1, golesTeam2;
            bool ans1 = true, ans2 = false;

            /*for que organiza la entrada (el resultado del partido) en 4 variables*/
            for(int i = 0; i < resultPartidos.size(); ++i){
                if(resultPartidos[i] == '#' && ans1 == true){
                    primerTeam = resultPartidos.substr(0, i);
                    ans1 = false;
                    ans2 = true;
                }
                else if(resultPartidos[i] == '#' && ans2 == true){
                    segundoTeam = resultPartidos.substr(i+1, -1);
                    ans2 = false;
                }
            }
            bool ans3 = true;
            for(int i = 0; i < resultPartidos.size(); ++i){
                if(resultPartidos[i] == '#' && ans3 == true){
                    ++i;
                    while(resultPartidos[i] != '@'){
                        gol1+=resultPartidos[i];
                        ++i;
                    }
                    ++i;
                    while(resultPartidos[i] != '#'){
                        gol2+=resultPartidos[i];
                        ++i;
                    }

                    golesTeam1 = convertidorStringEntero(gol1);
                    golesTeam2 = convertidorStringEntero(gol2);
                    ans3 = false;
                }
            }

            /*for que busca al equipo y le suma a juegos jugados, los goles que hizo y recibio en el partido,
            y si gano, empato o perdio el partido*/
            for(int i = 0; i < vecEquipos.size(); ++i){
                if(vecEquipos[i].getNombreTeam() == primerTeam){
                    vecEquipos[i].setGamesPlayed();
                    vecEquipos[i].setGoal(golesTeam1, golesTeam2);
                    if(golesTeam1 > golesTeam2){
                        vecEquipos[i].setWins();
                    }
                    else if(golesTeam1 == golesTeam2){
                        vecEquipos[i].setTies();
                    }
                    else{
                        vecEquipos[i].setLosses();
                    }
                }
                else if(vecEquipos[i].getNombreTeam() == segundoTeam){
                    vecEquipos[i].setGamesPlayed();
                    vecEquipos[i].setGoal(golesTeam2, golesTeam1);
                    if(golesTeam2 > golesTeam1){
                        vecEquipos[i].setWins();
                    }
                    else if(golesTeam2 == golesTeam1){
                        vecEquipos[i].setTies();
                    }
                    else{
                        vecEquipos[i].setLosses();
                    }
                }
                
            }

            --nPartidos;

        }

        
        sort(vecEquipos.begin(), vecEquipos.end());
        int contador = 1;
        cout << torneoName << endl;
        for(vector<Fotball>::iterator it = vecEquipos.begin(); it != vecEquipos.end(); ++it){
            cout << contador << ") ";
            it->printResult();
            ++contador;
        }
        


        
        --nTorneos;
    }
    return 0;
}