#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
// Funcion auxiliar para validar entrada numerica
double leerNumero(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente nuevamente." << endl;
        } else {
            return valor;
        }
    }
}

// Calculo de Tiempo de Ejecucion y Ciclos de Reloj ( Ejercicio 1)

void ejercicio1() {
    cout << "\n=== Ejercicio 1: Ciclos y Tiempo Total ===" << endl;

    int k = (int) leerNumero("Ingrese el numero de etapas del pipeline (k): ");
    int n = (int) leerNumero("Ingrese el numero total de instrucciones (n): ");
    double tau = leerNumero("Ingrese el tiempo de ciclo de reloj CR (en ns): ");

    int ciclos = k + (n - 1);
    double Tk = ciclos * tau;

    cout << "\n--- Resultados ---" << endl;
    cout << "Ciclos totales = k + (n - 1) = " << k << " + (" << n << " - 1) = "
         << ciclos << " ciclos" << endl;
    cout << "Tiempo total Tk = ciclos * CR = " << ciclos << " * " << tau
         << " = " << Tk << " ns" << endl;
    cout << endl;
}

//  Ganancia de Velocidad (Speedup) Real vs. Ideal (Ejercicio 2)

void ejercicio2() {
    cout << "\n=== Ejercicio 2: Speedup Real vs Ideal ===" << endl;

    int k = (int) leerNumero("Ingrese el numero de etapas del pipeline (k): ");
    int n = (int) leerNumero("Ingrese el numero total de instrucciones (n): ");
    double tau = leerNumero("Ingrese el tiempo de ciclo de reloj (ns): ");

    int ciclos = k + (n - 1);
    double Tk = ciclos * tau;
    double T1 = n * k * tau; 

    double Sk = T1 / Tk;
    double Sideal = k;
    double eficiencia = (Sk / Sideal) * 100.0;

    cout << "\n--- Resultados ---" << endl;
    cout << "T1 (no segmentado) = n * k * tau = " << n << " * " << k << " * "
         << tau << " = " << T1 << " ns" << endl;
    cout << "Tk (segmentado)    = " << Tk << " ns" << endl;
    cout << "Speedup Sk = T1 / Tk = " << T1 << " / " << Tk << " = "
         << fixed << setprecision(2) << Sk << endl;
    cout << "Speedup ideal (n -> infinito) = k = " << Sideal << endl;
    cout << "Eficiencia alcanzada = (Sk / Sideal) * 100 = "
         << fixed << setprecision(1) << eficiencia << " %" << endl;
    cout << endl;
}

// Menu principal

void mostrarMenu() {
    cout << "==========================================" << endl;
    cout << " GUIA PRACTICA - PIPELINING " << endl;
    cout << "==========================================" << endl;
    cout << "1. Calculo de tiempo de ejecucion y ciclos de Reloj (Ejercicio 1)" << endl;
    cout << "2. Ganancia de Velocidad (Speedup) Real vs. Ideal (Ejercicio 2)" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n" << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 0:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n" << endl;
        }

    } while (opcion != 0);

    return 0;
}