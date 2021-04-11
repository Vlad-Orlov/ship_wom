#ifndef OPNOVICEDETECTORMESSENGER_HH
#define OPNOVICEDETECTORMESSENGER_HH

#include "globals.hh"
#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "OpNoviceDetectorConstruction.hh"

class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;
class G4UIcmdWithADouble;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;
class G4UIcmd;

class OpNoviceDetectorMessenger: public G4UImessenger
{
public:
    OpNoviceDetectorMessenger(OpNoviceDetectorConstruction* );
    virtual ~OpNoviceDetectorMessenger();
    virtual void SetNewValue(G4UIcommand*, G4String);

private:
    OpNoviceDetectorConstruction* fDet;
    G4UIdirectory* fWOMdir;
    G4UIcmdWithoutParameter* updateGeoCmd;
    G4UIcmdWithADoubleAndUnit* boxWidthCmd;
};

#endif // OPNOVICEDETECTORMESSENGER_HH
