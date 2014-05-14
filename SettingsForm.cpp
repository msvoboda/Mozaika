//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "SettingsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TOptionForm *OptionForm;
//---------------------------------------------------------------------------
__fastcall TOptionForm::TOptionForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOptionForm::Button1Click(TObject *Sender)
{
	Close();
}

void TOptionForm::setPicture(TList *array)
{
    _array = array;
}

void TOptionForm::savePicture(TList *array)
{

}
//---------------------------------------------------------------------------
