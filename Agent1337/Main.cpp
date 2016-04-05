#include <SFML/Graphics.hpp>

int main()
{
	float m_originalShapeRadius = 350.f;
	float m_shapeRadius = m_originalShapeRadius;
	float m_outlineWidth = -5;
	bool m_outlineGrowing = true;
	bool m_circleGrowing = true;

	sf::RenderWindow window(sf::VideoMode(m_originalShapeRadius*2, m_originalShapeRadius*2), "1337");
	sf::CircleShape shape(m_shapeRadius);

	shape.setFillColor(sf::Color::Blue);
	shape.setOutlineThickness(m_outlineWidth);
	shape.setOutlineColor(sf::Color::White);

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		if (m_outlineWidth > -(m_shapeRadius*0.1f))
		{
			m_outlineGrowing = true;
		}
		else if (m_outlineWidth < -(m_shapeRadius*0.9f))
		{
			m_outlineGrowing = false;
		}
		if (m_shapeRadius > m_originalShapeRadius)
		{
			m_circleGrowing = false;
		}
		else if (m_shapeRadius < (m_originalShapeRadius/100))
		{
			m_circleGrowing = true;
		}


		if (m_outlineGrowing)
		{
			m_outlineWidth -= 0.1f;
		}
		else if (!m_outlineGrowing)
		{
			m_outlineWidth += 0.1f;
		}
		if (m_circleGrowing)
		{
			m_shapeRadius += 0.01f;
		}
		else if (!m_circleGrowing)
		{
			m_shapeRadius -= 0.01f;
		}

		shape.setOutlineThickness(m_outlineWidth);
		shape.setRadius(m_shapeRadius);
		shape.setPointCount(m_shapeRadius / 2);
		shape.setPosition((m_originalShapeRadius - m_shapeRadius), (m_originalShapeRadius - m_shapeRadius));

		window.draw(shape);
		window.display();
	}

	return 0;
}