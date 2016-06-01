#ifndef ENGINE_H
#define ENGINE_H

class engine
{
private:
	char x;
	char y;
public:
	engine();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void enable_magnet();
	void disable_magnet();
	~engine();

};

#endif // ENGINE_H
