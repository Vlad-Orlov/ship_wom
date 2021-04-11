#include "OpNoviceDetectorMessenger.hh"
#include "OpNoviceDetectorConstruction.hh"

OpNoviceDetectorMessenger::OpNoviceDetectorMessenger(OpNoviceDetectorConstruction* detector):
    fDet(detector)
{
    fWOMdir = new G4UIdirectory("/WOMdir/");
    fWOMdir -> SetGuidance("Change size of WOM box");

    boxWidthCmd = new G4UIcmdWithADoubleAndUnit("/WOMdir/boxWidthCmd", this);
    boxWidthCmd->SetGuidance("Set new width of the WOM box (in z)");
    boxWidthCmd->SetParameterName("SteelZ", false);
    boxWidthCmd->SetUnitCategory("Length");
    boxWidthCmd->SetRange("SteelZ>0. && SteelZ<1000");
    boxWidthCmd->SetDefaultValue(335.);
    boxWidthCmd->SetDefaultUnit("mm");
    boxWidthCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

    updateGeoCmd = new G4UIcmdWithoutParameter("/WOMdir/updateGeo",this);
    updateGeoCmd->SetGuidance("Update Geometry");
    updateGeoCmd->AvailableForStates(G4State_PreInit,G4State_Idle);


}

OpNoviceDetectorMessenger::~OpNoviceDetectorMessenger()
{
    delete boxWidthCmd;
    delete updateGeoCmd;
}

void OpNoviceDetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
    if( command == boxWidthCmd )
    {
        fDet->SetBoxWidth(boxWidthCmd->GetNewDoubleValue(newValue));
    }

    if( command == updateGeoCmd )
    {
        fDet->UpdateGeometry();
    }
}

