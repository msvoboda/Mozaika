//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
#include <FMX.MobilePreview.hpp>
//---------------------------------------------------------------------------
USEFORM("SettingsForm.cpp", OptionForm);
USEFORM("MainForm.cpp", MozaikaForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
        	Application->Initialize();
		Application->FormFactor->Orientations = TScreenOrientations() << TScreenOrientation::Landscape << TScreenOrientation::InvertedLandscape;
		Application->CreateForm(__classid(TMozaikaForm), &MozaikaForm);
		Application->CreateForm(__classid(TOptionForm), &OptionForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
