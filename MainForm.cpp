//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "SettingsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMozaikaForm *MozaikaForm;

const int rows=8;
const int columns=15;
const int colors=5;

//---------------------------------------------------------------------------
__fastcall TMozaikaForm::TMozaikaForm(TComponent* Owner)
	: TForm(Owner)
{
	array = new TList();
		tool_array = new TList();
}
//---------------------------------------------------------------------------
void TMozaikaForm::BuildGrid()
{
    float jeden = (GridTool->Height-14)/7;
    GridTool->Width = jeden +8;
    GridTool->ItemHeight = jeden;
    GridTool->ItemWidth = jeden;

    float wjeden=(float)(GridMozaika->Width-columns)/(float)columns;
    float hjeden=(float)(GridMozaika->Height-rows)/(float)rows;
    ///
    GridMozaika->ItemHeight = hjeden;
    GridMozaika->ItemWidth =  wjeden;

    int tools_h = (PanelMain->Height/colors);

    for(int i = 0; i <GridMozaika->ChildrenCount;i++)
    {
    	TShape* sh = (TShape*)GridMozaika->Children->Items[i];
	array->Add(sh);
    }

    tool_array->Add(RectangleWhite);
    tool_array->Add(RectangleBlack);
    tool_array->Add(RectangleBrown);
    tool_array->Add(RectangleYellow);
    tool_array->Add(RectangleBlue);
    tool_array->Add(RectangleGreen);
    tool_array->Add(RectangleRed);
    /*
    for(int i = 0; i < 64;i++)
    {
	TRectangle *rect = new TRectangle(this);
        rect->Fill->Color=(TAlphaColor)claWhite;
        GridMozaika->AddObject(rect);
    }
    */
}
void __fastcall TMozaikaForm::FormShow(TObject *Sender)
{
  BuildGrid();
}
//---------------------------------------------------------------------------

void __fastcall TMozaikaForm::RectangleRedClick(TObject *Sender)
{
   RectangleRed->Stroke->Color = (TAlphaColor)claBlack;
   RectangleRed->Stroke->Thickness = 1;
   RectangleGreen->Stroke->Color = (TAlphaColor)claBlack;
   RectangleGreen->Stroke->Thickness = 1;
   RectangleBlue->Stroke->Color = (TAlphaColor)claBlack;
   RectangleBlue->Stroke->Thickness = 1;
   RectangleYellow->Stroke->Color = (TAlphaColor)claBlack;
   RectangleYellow->Stroke->Thickness = 1;
   RectangleBrown->Stroke->Color = (TAlphaColor)claBlack;

   RectangleBlack->Stroke->Color = (TAlphaColor)claBlack;
   RectangleBlack->Stroke->Thickness = 1;
   RectangleWhite->Stroke->Color = (TAlphaColor)claBlack;
   RectangleWhite->Stroke->Thickness = 1;

   select = (TShape*)Sender;
   select->Stroke->Color = (TAlphaColor)claRed;
   select->Stroke->Thickness = 2.0;
}
//---------------------------------------------------------------------------

void __fastcall TMozaikaForm::Rectangle1Click(TObject *Sender)
{
	TShape *click = (TShape*)Sender;
	if (select != NULL)
        {
          click->Fill = select->Fill;
          click->Tag = select->Tag;
        }
}
//---------------------------------------------------------------------------


void __fastcall TMozaikaForm::ButtonNewClick(TObject *Sender)
{
    for(int i = 0; i <GridMozaika->ChildrenCount;i++)
    {
        TShape* sh = (TShape*)GridMozaika->Children->Items[i];
        sh->Fill = RectangleWhite->Fill;
        sh->Tag = (NativeInt)0;
        //array->Add(sh);
    }
}
//---------------------------------------------------------------------------


void __fastcall TMozaikaForm::ButtonSettingsClick(TObject *Sender)
{
	OptionForm->setPicture(array);
        OptionForm->setTool(tool_array);
        OptionForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMozaikaForm::Rectangle1MouseEnter(TObject *Sender)
{
    	TShape *click = (TShape*)Sender;
	if (select != NULL)
        {
          click->Fill = select->Fill;
          click->Tag = select->Tag;
        }
}
//---------------------------------------------------------------------------

