/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CBoatSA.h
 *  PURPOSE:     Header file for boat vehicle entity class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include <game/CBoat.h>
#include "CVehicleSA.h"

class CBoatSAInterface : public CVehicleSAInterface
{
public:
    uint32               pad1[3];                                 // 1440
    uint32               BoatFlags;                               // 1452
    RwFrame*             pBoatParts[11];                          // 1456 [[ find out correct size
    uint32               pad2[3];                                 // 1500
    uint16               pad3;                                    // 1512
    uint8                pad4[2];                                 // 1514
    uint32               pad5[3];                                 // 1516
    tBoatHandlingDataSA* pBoatHandlingData;                       // 1528
    uint32               pad6[5];                                 // 1532
    CVector              vecUnk1;                                 // 1552
    CVector              vecUnk2;                                 // 1564
    class CParticleFx*   pBoatPropellerSplashParticle;            // 1576
    uint32               pad7[4];                                 // 1580
    uint8                pad8;                                    // 1596
    uint8                ucPadUsingBoat;                          // 1597  [[ see class CPad
    uint8                pad9[2];                                 // 1598
    uint32               pad10[106];                              // 1600
};

class CBoatSA final : public virtual CBoat, public virtual CVehicleSA
{
private:
    CBoatHandlingEntrySA* m_pBoatHandlingData = nullptr;
public:
    CBoatSA(CBoatSAInterface* pInterface);

    CBoatSAInterface* GetBoatInterface() { return reinterpret_cast<CBoatSAInterface*>(GetInterface()); }

    CBoatHandlingEntry* GetBoatHandlingData();
    void                SetBoatHandlingData(CBoatHandlingEntry* pHandling);
};
