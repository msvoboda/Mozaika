//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "SettingsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

#include "System.IOUtils.hpp"
#include "System.SysUtils.hpp"

TOptionForm *OptionForm;
UnicodeString _path;
//---------------------------------------------------------------------------
__fastcall TOptionForm::TOptionForm(TComponent* Owner)
	: TForm(Owner)
{
  _path = System::Sysutils::IncludeTrailingBackslash(System::Ioutils::TPath::GetSharedDocumentsPath());
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

void TOptionForm::setTool(TList *load_array)
{
    _load_array = load_array;
}
//---------------------------------------------------------------------------


void __fastcall TOptionForm::DbmozaikaConnectionAfterConnect(TObject *Sender)
{

	SQLCreate->CommandText = "CREATE TABLE IF NOT EXISTS pictures ( id INTEGER PRIMARY KEY, name VARCHAR( 60 ), data VARCHAR( 77 ));";
        int rec = SQLCreate->ExecSQL(true);
	if (rec > 0) {

	}
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::ButtonSaveClick(TObject *Sender)
{
	TStringList *data = new TStringList();
        data->Add(EditName->Text);
        UnicodeString line="";
        for(int i = 0; i<_array->Count; i++)
        {
            TShape *sh = (TShape*) _array->Items[i];
            line+=(UnicodeString)sh->Tag;
        }
        data->Add(line);
	System::Ioutils::TFile::WriteAllText(_path+EditName->Text+".pict", data->Text);
        delete data;

        Refresh();
	/*
	UnicodeString query = "INSERT INTO pictures (name, data) VALUES ('"+EditName->Text+"','00000000000000000000000000000000000000000000000000000000000000000000000000000')";

	SQLInsert->SQL->Clear();
        SQLInsert->SQL->Add(query);
        int rec = SQLInsert->ExecSQL(true);
	if (rec > 0) {
             Refresh();
	}*/
}

void __fastcall TOptionForm::Refresh(){
  ListBox->Items->Clear();
  ChDir(_path);
  TSearchRec sr;
  int iAttributes = 0;
  iAttributes |= faReadOnly;
  iAttributes |= faHidden;
  iAttributes |= faSysFile;
  iAttributes |= faVolumeID;
  iAttributes |= faDirectory;
  iAttributes |= faArchive;
  iAttributes |= faAnyFile;
  if (FindFirst(_path+"*.pict", iAttributes, sr) == 0)
  {
    do
    {
      if ((sr.Attr & iAttributes) == sr.Attr)
      {
           UnicodeString file = sr.Name;
           ListBox->Items->Add(file);
      }
    } while (FindNext(sr) == 0);
  }

  if (ListBox->Items->Count > 0) {
      ButtonOpen->Enabled = true;
  }

    /*
    //SQLQuery->CommandText = "select * from pictures;";
    try
    {
        PicturesTable->Open();
        PicturesTable->Refresh();
        PicturesTable->First();
        do
        {
                UnicodeString name = PicturesTable->FieldByName("name")->AsString;
                UnicodeString data = PicturesTable->FieldByName("data")->AsString;
                TMozaikaPicture *pict = new TMozaikaPicture();
                pict->name = name;
                pict->data = data;
                ListBox->Items->AddObject(name,(TObject*)pict);
                PicturesTable->Next();
        }
        while(PicturesTable->Eof==false);
    }
    __finally
    {
    	PicturesTable->Close();
    }*/
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::FormShow(TObject *Sender)
{
 Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TOptionForm::ButtonOpenClick(TObject *Sender)
{
  int sel_idx = ListBox->ItemIndex;
 if (sel_idx != -1) {
   TStringList *data = new TStringList();
   data->LoadFromFile(_path+ListBox->Items->Strings[sel_idx]);
   try
   {
      LabelName->Text=data->Strings[0];
      UnicodeString line = data->Strings[1];
      for(int i = 1; i <= line.Length();i++)
      {
      	 UnicodeString znak = line[i];
         int val = znak.ToInt();
         TShape *sh = (TShape*)_array->Items[i];
         TShape *tool = (TShape*)_load_array->Items[val];
         sh->Fill = tool->Fill;
      }
   }
   catch(...)
   {

   }
 }
}
//---------------------------------------------------------------------------

