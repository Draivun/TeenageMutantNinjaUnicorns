///@file

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "drawable.hpp"
#include "image.hpp"

/// \class button
///
/// \brief Creates a button at a specific place on the screen
///
/// This class is used to make a button that is placed at a certain
/// position. Right now a lot of math is done in this class to make 
/// sure the button is in the exact middle of the screen, together
/// with the ( adjustable ) text on the button. 
/// 
/// Note: We would like to transfer all the math done in here to #menu.
/// However, this has low priority . 
///
/// \date 27-1-2017
class button {
    private:
	float start_height_y;
	float start_height_x;
	int position;

	std::string whats_on_the_button;
	sf::Texture texture;
        sf::RectangleShape button_background;

	sf::Font font;
	sf::Text text;
    public:
	/// \brief constructor to make button
	///
	/// This constructor receives 2 floats to determine the start position of the button.
	/// The position determines at which of the three positions it will render 
	/// according to screen size. The string is the text that will be displayed
	/// on the button. 
	///
	///
	/// \param[in] start_height_y Starting height Y coordinate
	/// \param[in] start_height_x Starting height X coordinate
	/// \param[in] position     The postion for the button ( 1 - 2 - 3)
	/// \param[in] whats_on_the_button std::string, the text on the button 
	button(float start_height_y = 0.0, float start_height_x = 0.0, int position = 0, std::string whats_on_the_button = " ");

	/// \brief Function to draw the button & the text
	///
	/// Function to draw both the button and the text on the given window. 
	///
	/// \param[in] window The display window
	void draw(sf::RenderWindow & window);

	/// \brief Function that decides what gets drawn where. 
	///
	/// This function decides where to draw the buttons. The purpose of all 
	/// the math is to determine the place on the screen for the button, so it
	/// sits right in the middle of the screen. The draw position for the text
	/// is also adjusted for length of the given std::string. This is also the
	/// function that uses the position parameter to determine where the position gets 
	/// drawn.
	///
	void setup();

	/// \brief get objects floatrect
	///
	/// This function uses the getGlobalBounds function from te object to get the
	/// bounding box of the object. It returns this as a floatrect. This return value
	/// can be used to check if the object touches another object.
	///
	/// \param[in] position The objects initial position
	/// \param[in] image_name The name of the image that has to be loaded
	/// \retval sf::FloatRect {The bounding box of the sprite object created in this class}
	sf::FloatRect getGlobalBounds();
};
#endif //BUTTON_HPP
