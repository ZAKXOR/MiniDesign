#include "Application.h"
#include "StrategieAffichage.h"
#include "StrategieConstruction.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<Point*> creerPoints(const string& args) {
    vector<Point*> points;
    istringstream iss(args);
    string token;
    
    while (iss >> token) {
        if (token[0] == '(') {
            int x, y;
            char c;
            istringstream pointStream(token);
            pointStream >> c >> x >> c >> y;
            points.push_back(new Point(x, y));
        }
    }
    return points;
}

int main(int argc, char* argv[]) {
    Application app;
    
    string args;
    if (argc > 1) {
        ostringstream oss;
        for (int i = 1; i < argc; ++i) oss << argv[i] << " ";
        args = oss.str();
    } else {
        cout << "Entrez les points au format (x,y) :\n> ";
        getline(cin, args);
    }
    
    vector<Point*> points = creerPoints(args);
    app.ajouterPoint(points);
    
    app.modifierStrategieAffichage(new StrategieAffichage1);

    string cmd;
    
    while (true) {
        cout << "\nCommandes:\n"
             << "a  - Afficher les points et les nuages\n"
             << "o1 - Afficher l'orthèse avec les textures des points\n"
             << "o2 - Afficher l'orthèse avec les IDs des points\n"
             << "f  - Fusionner des points dans un nuage (et appliquer texture)\n"
             << "d  - Deplacer un point (ID)\n"
             << "s  - Supprimer un point (ID)\n"
             << "c1 - Créer les surfaces selon l'ordre des IDs\n"
             << "c2 - Créer les surfaces selon la distance minimale\n"
             << "q  - Quitter\n> ";
        getline(cin, cmd);

        if (cmd == "q") {
            break;
        }
        else if (cmd == "a") {
            app.afficherPointsEtNuage();
        }
        else if (cmd == "o1") {
            app.modifierStrategieAffichage(new StrategieAffichage1);
            app.afficherGrille();
        }
        else if (cmd == "o2") {
            app.modifierStrategieAffichage(new StrategieAffichage2);
            app.afficherGrille();
        }
        else if (cmd == "f") {
            cout << "Entrez les IDs des points à fusionner (séparés par des espaces): ";
            string line;
            getline(cin, line);
            istringstream iss(line);
            vector<int> ids;
            int id;
            while (iss >> id) {
                ids.push_back(id);
            }
            app.fusionnerPoints(ids);
        }
        else if (cmd == "d") {
            cout << "Entrez l'ID du point: ";
            int id;
            cin >> id;
            cout << "Entrez la nouvelle position (x y): ";
            int x, y;
            cin >> x >> y;
            cin.ignore();
            app.deplacerPoint(id, x, y);
        }
        else if (cmd == "s") {
            cout << "Entrez l'ID du point à supprimer: ";
            int id;
            cin >> id;
            cin.ignore();
            app.supprimerPoint(id);
        }
        else if (cmd == "c1") {
            app.modifierStrategieConstruction(new StrategieConstruction1());
            cout << "Surfaces créées selon l'ordre des IDs\n";
        }
        else if (cmd == "c2") {
            app.modifierStrategieConstruction(new StrategieConstruction2());
            cout << "Surfaces créées selon la distance minimale\n";
        }
        else {
            cout << "Commande inconnue\n";
        }
    }
    return 0;
}