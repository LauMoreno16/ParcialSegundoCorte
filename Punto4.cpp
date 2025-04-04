// cuentabancaria.h
class CuentaBancaria {
    private:
        float saldo;
        std::string numeroCuenta;
        bool retirosBloquedos;
    
    public:
        CuentaBancaria(float saldo_inicial, std::string numero_cuenta);
        void depositar(float monto);
        bool retirar(float monto);
        void bloquearRetiros();
        void desbloquearRetiros();
        float obtenerSaldo();
    };
    
    // cuentabancaria.cpp
    CuentaBancaria::CuentaBancaria(float saldo_inicial, std::string numero_cuenta) {
        saldo = saldo_inicial;
        numeroCuenta = numero_cuenta;
        retirosBloquedos = false;
    }
    
    void CuentaBancaria::depositar(float monto) {
        saldo += monto;
    }
    
    bool CuentaBancaria::retirar(float monto) {
        if (saldo >= monto && !retirosBloquedos) {
            saldo -= monto;
            return true;
        } else {
            return false;
        }
    }
    
    void CuentaBancaria::bloquearRetiros() {
        retirosBloquedos = true;
    }
    
    void CuentaBancaria::desbloquearRetiros() {
        retirosBloquedos = false;
    }
    
    float CuentaBancaria::obtenerSaldo() {
        return saldo;
    }
    
    // contador_energia.h
    class ContadorEnergia {
    private:
        int id;
        float consumoTotal;
    
    public:
        ContadorEnergia(int id_medidor, float consumo_inicial);
        void registrarConsumo(float consumo);
        int obtenerID();
        float obtenerConsumoTotal();
    };
    
    // contador_energia.cpp
    ContadorEnergia::ContadorEnergia(int id_medidor, float consumo_inicial) {
        id = id_medidor;
        consumoTotal = consumo_inicial;
    }
    
    void ContadorEnergia::registrarConsumo(float consumo) {
        consumoTotal += consumo;
    }
    
    int ContadorEnergia::obtenerID() {
        return id;
    }
    
    float ContadorEnergia::obtenerConsumoTotal() {
        return consumoTotal;
    }
    
    // main.cpp
    #include <iostream>
    #include <fstream>
    #include <vector>
    
    int main() {
        // Paso 1: Crear tres objetos ContadorEnergia con ID y consumo inicial
        std::vector<ContadorEnergia> medidores;
        medidores.emplace_back(1, 100.0);
        medidores.emplace_back(2, 50.0);
        medidores.emplace_back(3, 75.0);
    
        // Paso 2: Simular el registro de consumo para cada medidor
        for (auto& medidor : medidores) {
            medidor.registrarConsumo(10.0);
        }
    
        // Paso 3: Generar un archivo de texto "reporte.txt" con el ID y el consumo total de cada medidor
        std::ofstream reporte("reporte.txt");
        if (reporte.is_open()) {
            for (const auto& medidor : medidores) {
                reporte << "ID: " << medidor.obtenerID() << ", Consumo total: " << medidor.obtenerConsumoTotal() << std::endl;
            }
            reporte.close();
            std::cout << "Reporte generado en 'reporte.txt'." << std::endl;
        } else {
            std::cerr << "No se pudo abrir el archivo 'reporte.txt'." << std::endl;
        }
    
        return 0;
    }