/**/


//Esta línea incluye la librería iostream para usar cout y cin :
#include <iostream>
#include <conio.h>
//Esta línea incluye la librería SFML / Graphics.hpp para usar el círculo :
#include <SFML/Graphics.hpp>


//Usa el espacio de nombres std :
using namespace std;

//Comienza la función main :
int main()
{
    int salir = 0;

    do {
        try
        {
            system("cls");
            cin.exceptions(istream::failbit); // capta bits fallidos
            //Solicita al usuario el radio del círculo
            int radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;

            //Crea una ventana con un título en la pantalla :
            //Crear ventana
            sf::RenderWindow window(sf::VideoMode(800, 600), "Circulo");

            //Crea un círculo con el radio ingresado por el usuario :
            //Crear el circulo
            sf::CircleShape circulo(radio);
            circulo.setFillColor(sf::Color::Blue);
            circulo.setPosition(400, 300);
            circulo.setOrigin(radio, radio);

            //Ciclo de visualización para mantener la ventana abierta :
            //Ciclo de visualización
            while (window.isOpen())
            {
                //Manejo de eventos
                sf::Event event;
                while (window.pollEvent(event))
                {
                    //Si se cierra la ventana
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                //Limpiar la ventana
                window.clear();

                //Dibujar el circulo
                window.draw(circulo);

                //Mostrar la imagen
                window.display();
            }
        }
        catch (exception fail)
        {
            cin.clear();
            string tmp;
            getline(cin, tmp);
            cout << "Solo se puden ingresar numeros, intente nuevamente \n \n";
            _getch();
        }
    } while (salir != 1);
}