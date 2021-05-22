/**
 * @file Application.h
 * @brief plik zawiekaj¹cy klase Application
 */

#pragma once
#include "stdafx.h"
#include "Pen.h"
#include "Mouse.h"
#include "Block.h"
#include "Block.cpp"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Brush.h"
#include "DrawableObject.h"


 /** Klasa obiektu aplikacji*/
class Application
{
private:
	sf::RenderWindow window; ///< Obiekt okna
	Mouse mouse; ///< obiekt myszki
public:
	/** Konstruktor klasy Application
	 * @param windowWidth szerokoœæ okna
	 * @param windowHeight wysokoœæ okna
	 * @param filename nazwa pliku do którego ma siê zapisaæ praca
	 */
	Application(const int& windowWidth = 800, const int& windowHeight = 400, const std::string& filename = "Paint");
	
	/** Dekonstruktor klasy Application */
	~Application();

	/** Funkcja która uruchamia program */
	void run();
	
	bool isLeftButtonPressed; ///< zmienna mówi¹ca czy lewy przycisk myszki jest naciœniêty
	bool isShiftPressed; ///< zmienna mówi¹ca czy przycisk Shift jest naciœniêty
	bool isControlPressed; ///< zmienna mówi¹ca czy przycisk Control jest naciœniêty
	bool isZPressed; ///< zmienna mówi¹ca czy przycisk Z jest naciœniêty
	bool isYPressed; ///< zmienna mówi¹ca czy przycisk Y jest naciœniêty
	bool isSceneChanged; ///< zmienna mówi¹ca czy scena siê zmieni³a
	bool isSPressed; ///< zmienna mówi¹ca czy przycisk S jest naciœniêty
	bool toDraw;  ///< zmienna mówi¹ca czy mo¿na kontynu³owaæ rysowanie nastêpnego obiektu
	bool ColorChanged; ///< zmienna mówi¹ca czy kolor siê zmieni³
	bool outLineIsSet; ///< zmienna mówi¹ca czy obramowanie jest ustawione
	bool doSave; ///< zmienna mówi¹ca czy nale¿y zapisaæ aktualn¹ scene
	std::string filename; ///< nazwa pliku
	sf::Text thicknessText; ///< tekst mówi¹cy o aktualnej gruboœci
	sf::Font font; ///< czcionka
	std::vector<BaseBlock*> allBlockObject = {}; ///<  wektor wzkaŸniki do obiektów bloku
	std::vector<DrawableObject*> allDrawableObjects = {}; ///<  wektor wzkaŸniki do obiektów do narysowania
	std::vector< DrawableObject*> allObjectsInClipboard = {}; ///<  wektor wzkaŸniki do obiektów w schowku
	std::vector<sf::Texture> allTextures; ///<  wektor zawieraj¹cy wszystkie tekstury

private:
	/** Funkcja obs³ugi zdarzeñ */
	void events();

	/** Funkcja która aktualizuje wszytkie obiekty
	 * @param window okno do rysowania
	 */
	void updateAll(sf::RenderWindow& window);

	/** Funkcja która rysuje wszystkie obiekty na oknie  
	 * @param window okno do rysowania
	 */
	void drawAll(sf::RenderWindow& window);
	/** Funkcja aktualizuj¹ca schowek */
	void updateClipboard();
	/** Funkcja usuwaj¹ca schowek */
	void clearClipboard();
	/** Funkcja sprawdzaj¹ca czy nale¿y zapisaæ */
	void saveFile();
	/** Funkcja tworz¹ca wszystkie pocz¹tkowe obiekty */
	void createEverything();
	/** Funkcja która tworzy nowe obiekty na oknie */
	void drawFunction();
	/** Funkcja która sprawdza czy obiekt jest klikniêty, jeœli tak to jest wykonywana odpowiednia operacja */
	void isBlockClicedFunction();
};

