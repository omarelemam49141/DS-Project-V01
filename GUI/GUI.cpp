#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}
//omar
double GUI::GetNumber() const
{
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		switch (Key)
		{
		case 50:
			return 2;
		case 52:
			return 4;
		case 72:
		case 104:
			return 0.5;
		case 113:
		case 81:
			return 0.25;
		default:
			PrintMessage("Enter a valid factor (h:0.5, q:0.25, 2, 4)");
			return 1;
		}
		PrintMessage(to_string(Key) + " is pressed");
	}
}

//omar
bool GUI::ExceedDrawingArea(int minX, int minY, int maxX, int maxY)
{
	int DrawAreaHeight = UI.height - UI.StatusBarHeight - UI.ToolBarHeight;
	if (maxX > (UI.wx + UI.width) || (minX < UI.wx) || maxY > (UI.wy + UI.ToolBarHeight + DrawAreaHeight) || minY < (UI.wy + UI.ToolBarHeight))
	{
		return true;
	}
	return false;
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_HEX: return DRAW_HEX;
			case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_CHNG_BK_CLR: return CHNG_BK_CLR;
			case ITM_CHNG_FIG_CLR: return CHNG_FIG_CLR;
			case ITM_DELETE: return DEL;
			case ITM_MOVE_BACK: return SEND_BACK;
			case ITM_MOVE_FRONT: return BRNG_FRNT;
			case ITM_RSZ_QRT: return QUARTERED_RESIZE;
			case ITM_RSZ_HALF: return HALFED_RESIZE;
			case ITM_RSZ_DOUBLE: return DOUBLED_RESIZE;
			case ITM_RSZ_QUADRUPLE: return QUADRUPLE_RESIZED;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//case ITM_SQUR2: return DRAW_SQUARE;
				//case ITM_ELPS: return DRAW_ELPS;
				//case ITM_HEX: return DRAW_HEX;
				//case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
				//case ITM_CHNG_FILL_CLR: return CHNG_FILL_CLR;
				//case ITM_CHNG_BK_CLR: return CHNG_BK_CLR;
				//case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY;
			case ITM_SWITCH_TO_DRAW_MODE: return TO_DRAW;

				//case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

	}

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\Menu_Elps.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_HEX.jpeg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\Menu_border.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\Menu_fill.jpg";
	MenuItemImages[ITM_CHNG_BK_CLR] = "images\\MenuItems\\Menu_bg.jpeg";
	MenuItemImages[ITM_CHNG_FIG_CLR] = "images\\MenuItems\\chgobjclr.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpeg";
	MenuItemImages[ITM_MOVE_BACK] = "images\\MenuItems\\back.jpg";
	MenuItemImages[ITM_MOVE_FRONT] = "images\\MenuItems\\front.jpg";
	MenuItemImages[ITM_RSZ_QRT] = "images\\MenuItems\\MenuResize0.25.jpg";
	MenuItemImages[ITM_RSZ_HALF] = "images\\MenuItems\\MenuResize0.5.jpg";
	MenuItemImages[ITM_RSZ_DOUBLE] = "images\\MenuItems\\MenuResize2.jpg";
	MenuItemImages[ITM_RSZ_QUADRUPLE] = "images\\MenuItems\\MenuResize4.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save-icon.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	//MenuItemImages[ITM_SQUR2] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_GAME1] = "images\\MenuItems\\game1.jpg";
	MenuItemImages[ITM_GAME2] = "images\\MenuItems\\game2.jpg";
	MenuItemImages[ITM_GAME3] = "images\\MenuItems\\game3.jpg";
	MenuItemImages[ITM_SWITCH_TO_DRAW_MODE] = "images\\MenuItems\\draw.jpg";
	//MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void GUI::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntBGColor() const	//get current filling color
{
	return UI.BkGrndColor;
}
//////////////////////////////////////////////////////////////////////////////////////////
	
color GUI::getCrntHighlightColor() const	//get current filling color
{
	return UI.HighlightColor;
}
///////////////////////////////////
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}
//////////////////////////////////////////////////////////////////////////////////////////
//Omar
void GUI::setCrntDrawColor(color clr)	//set current drwawing color
{
	UI.DrawColor = clr;
}
//Omar
void GUI::setCrntFillColor(color clr)	//set current drwawing color
{
	UI.FillColor = clr;
}
//Omar
void GUI::setCrntBGColor(color clr)	//set current drwawing color
{
	UI.BkGrndColor = clr;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);

}

//Omar
//Draw Ellipse
void GUI::DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

//Omar
//Draw Hexagon
void GUI::DrawHexagon(int *xCoords, int* yCoords, int vertexes ,GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(xCoords, yCoords, vertexes, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

