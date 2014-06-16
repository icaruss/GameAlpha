


#define FOLDER_BACKGROUND		"Backgrounds\\"
#define FOLDER_OBJECTS			"Objects\\"


#define IMAGE_BACKGROUND		"black-wood-background.jpg"
#define IMAGE_BALL				"donut.png"
#define IMAGE_PADDLE			"paddle.png"

typedef enum TAGS
{
	TAG_BACKGROUND	=			0,
	TAG_BALL		=			100,
	TAG_PADDLE		=			200,
	TAG_LABEL		=			2
}TAGS;

typedef enum Z_ORDER
{
	Z_ORDER_BACKGROUND	=			0,
	Z_ORDER_BALL		=			100,
	Z_ORDER_PADDLE		=			100,
	Z_ORDER_LABEL		=			2
}Z_ORDER;