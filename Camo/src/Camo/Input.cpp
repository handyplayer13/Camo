#include "Input.h"

#include <SFML/Graphics.hpp>

namespace Camo {

	bool Input::IsWKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	}

	bool Input::IsAKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	}

	bool Input::IsSKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	}

	bool Input::IsDKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	}

	bool Input::IsArrowUpKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	}

	bool Input::IsArrowLeftKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	}

	bool Input::IsArrowDownKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	}

	bool Input::IsArrowRightKeyPressed()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	}

	bool Input::IsLeftMouseButtonPressed()
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	bool Input::IsMiddleMouseButtonPressed()
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
	}

	bool Input::IsRightMouseButtonPressed()
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Right);
	}

	int Input::GetMousePositionX()
	{
		return sf::Mouse::getPosition().x;
	}

	int Input::GetMousePositionY()
	{
		return sf::Mouse::getPosition().y;
	}

}