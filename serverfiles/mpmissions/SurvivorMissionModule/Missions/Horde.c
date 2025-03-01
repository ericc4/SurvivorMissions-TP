class HordeMission extends SurvivorMissions {
    //Mission related entities
    ItemBase MissionObject;

    //Mission parameters
    int MsgDlyFinish = 300; //seconds, message delay time after player has finished mission
    int HordeDensity = 60; //infected, spawned in circle

    //Mission containers
    ref array < string > InfectedTypes = new array < string > ;

    //Mission variables

    override bool IsExtended() return false;

    void HordeMission() {
        //Mission mission timeout
        m_MissionTimeout = 2700; //seconds, mission duration time

        //Mission zones
        m_MissionZoneOuterRadius = 200.0; //meters (!Do not set lower than 200m), mission activation distance
        m_MissionZoneInnerRadius = 3.0; //meters (!Do not set outside of 1-5m), mission finishing distance to target object

        //Mission informant
        m_MissionInformant = "Dr. Legasov";

        //Set mission messages
        m_MissionMessage1 = "I got an emergency call from a heli pilot who crashed somewhere in the forests. He is injured but still alive. He was afraid that the infected will find him soon.";
        m_MissionMessage2 = "He made it to a house in the village near the crash site. He is well funded and he think he will stay in the house over the night where he treats his open wounds.";
        m_MissionMessage3 = "The house is at the ** " + m_MissionLocationDir + " side of " + m_MissionLocation + " **\nBe careful there may be infected and other survivors who want his money!";

        //Infected types
        //Male												//Female
        InfectedTypes.Insert("ZmbM_CitizenASkinny_Brown");
        InfectedTypes.Insert("ZmbF_JournalistNormal_White");
        InfectedTypes.Insert("ZmbM_priestPopSkinny");
        InfectedTypes.Insert("ZmbF_Clerk_Normal_White");
        InfectedTypes.Insert("ZmbM_HermitSkinny_Beige");
        InfectedTypes.Insert("ZmbF_CitizenANormal_Blue");
        InfectedTypes.Insert("ZmbM_CitizenBFat_Red");
        InfectedTypes.Insert("ZmbF_CitizenBSkinny");
        InfectedTypes.Insert("ZmbM_FishermanOld_Green");
        InfectedTypes.Insert("ZmbF_HikerSkinny_Grey");
        InfectedTypes.Insert("ZmbM_HunterOld_Autumn");
        InfectedTypes.Insert("ZmbF_SurvivorNormal_Orange");
        InfectedTypes.Insert("ZmbM_CitizenBFat_Blue");
        InfectedTypes.Insert("ZmbF_HikerSkinny_Green");
        InfectedTypes.Insert("ZmbM_MotobikerFat_Black");
        InfectedTypes.Insert("ZmbF_JoggerSkinny_Green");
        InfectedTypes.Insert("ZmbM_JoggerSkinny_Red");
        InfectedTypes.Insert("ZmbF_SkaterYoung_Striped");
        InfectedTypes.Insert("ZmbM_MechanicSkinny_Grey");
        InfectedTypes.Insert("ZmbF_BlueCollarFat_Red");
        InfectedTypes.Insert("ZmbM_HandymanNormal_Green");
        InfectedTypes.Insert("ZmbF_MechanicNormal_Beige");
        InfectedTypes.Insert("ZmbM_HeavyIndustryWorker");
        InfectedTypes.Insert("ZmbF_PatientOld");
        InfectedTypes.Insert("ZmbM_Jacket_black");
        InfectedTypes.Insert("ZmbF_ShortSkirt_beige");
        InfectedTypes.Insert("ZmbM_Jacket_stripes");
        InfectedTypes.Insert("ZmbF_VillagerOld_Red");
        InfectedTypes.Insert("ZmbM_HikerSkinny_Blue");
        InfectedTypes.Insert("ZmbF_JoggerSkinny_Red");
        InfectedTypes.Insert("ZmbM_HikerSkinny_Yellow");
        InfectedTypes.Insert("ZmbF_MilkMaidOld_Beige");
        InfectedTypes.Insert("ZmbM_PolicemanFat");
        InfectedTypes.Insert("ZmbF_VillagerOld_Green");
        InfectedTypes.Insert("ZmbM_PatrolNormal_Summer");
        InfectedTypes.Insert("ZmbF_ShortSkirt_yellow");
        InfectedTypes.Insert("ZmbM_JoggerSkinny_Blue");
        InfectedTypes.Insert("ZmbF_NurseFat");
        InfectedTypes.Insert("ZmbM_VillagerOld_White");
        InfectedTypes.Insert("ZmbF_PoliceWomanNormal");
        InfectedTypes.Insert("ZmbM_SkaterYoung_Brown");
        InfectedTypes.Insert("ZmbF_HikerSkinny_Blue");
        InfectedTypes.Insert("ZmbM_MechanicSkinny_Green");
        InfectedTypes.Insert("ZmbF_ParamedicNormal_Green");
        InfectedTypes.Insert("ZmbM_DoctorFat");
        InfectedTypes.Insert("ZmbF_JournalistNormal_Red");
        InfectedTypes.Insert("ZmbM_PatientSkinny");
        InfectedTypes.Insert("ZmbF_SurvivorNormal_White");
        InfectedTypes.Insert("ZmbM_ClerkFat_Brown");
        InfectedTypes.Insert("ZmbF_JoggerSkinny_Brown");
        InfectedTypes.Insert("ZmbM_ClerkFat_White");
        InfectedTypes.Insert("ZmbF_MechanicNormal_Grey");
        InfectedTypes.Insert("ZmbM_Jacket_magenta");
        InfectedTypes.Insert("ZmbF_BlueCollarFat_Green");
        InfectedTypes.Insert("ZmbM_PolicemanSpecForce");
        InfectedTypes.Insert("ZmbF_DoctorSkinny");
    }

    void ~HordeMission() {
        //Despawn all remaining mission objects
        if (m_MissionObjects) {
            Print("[SMM] Despawning " + m_MissionObjects.Count() + " mission objects from old mission...");
            for (int i = 0; i < m_MissionObjects.Count(); i++) {
                if (!m_MissionObjects.Get(i)) continue;
                else {
                    //Delete Object serverside
                    GetGame().ObjectDelete(m_MissionObjects.Get(i));
                }
            }
            m_MissionObjects.Clear();
        }

        //Despawn mission AI's
        if (m_MissionAIs) {
            if (m_MissionAIs.Count() > 0) {
                Print("[SMM] Despawning " + m_MissionAIs.Count() + " mission AI's from old mission...");
                for (int k = 0; k < m_MissionAIs.Count(); k++) {
                    GetGame().ObjectDelete(m_MissionAIs.Get(k));
                }
                m_MissionAIs.Clear();
            } else Print("[SMM] No mission AI's to despawn.");
        }

        //Delete PlayersInZone list & reset container takeaway
        if (m_PlayersInZone) m_PlayersInZone.Clear();
        if (m_ContainerWasTaken) m_ContainerWasTaken = false;
    }

    void SpawnObjects() {
        //Mission object is pilot bag
        MissionObject = ItemBase.Cast(GetGame().CreateObjectEx("Bear_Pink", m_MissionPosition, ECE_PLACE_ON_SURFACE));
        MissionObject.SetPosition(m_MissionPosition + "0 0.2 0");
        //MissionObject.PlaceOnSurface();

        //Get random loadout
        int selectedLoadout = Math.RandomIntInclusive(0, 11); //!Change randomization limit after adding new loadouts!

        //Spawn selected loadout items in mission object
        EntityAI weapon;

        if (selectedLoadout == 0) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble5000");
        } else if (selectedLoadout == 1) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble500");
        } else if (selectedLoadout == 2) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble1_Coin");
        } else if (selectedLoadout == 3) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble50");
        } else if (selectedLoadout == 4) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble10");
        } else if (selectedLoadout == 5) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble5");
        } else if (selectedLoadout == 6) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble1_Coin");
        } else if (selectedLoadout == 7) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble1_Coin");
        } else if (selectedLoadout == 8) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble1_Coin");
        } else if (selectedLoadout == 9) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble1_Coin");
        } else if (selectedLoadout == 10) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble100");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble1_Coin");
        } else if (selectedLoadout == 11) {
            weapon = MissionObject.GetInventory().CreateInInventory("Derringer_Grey");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
        }

        Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was " + selectedLoadout + ".");

        m_MissionObjects.Insert(MissionObject);

        Print("[SMM] Survivor Mission " + m_selectedMission + " :: " + m_MissionName + " ...mission deployed!");
    }

    void SpawnAIs() {
        //Spawn pilot
        DayZInfected InfectedPilot = DayZInfected.Cast(GetGame().CreateObjectEx("ZmbM_CommercialPilotOld_Olive", m_MissionPosition, ECE_PLACE_ON_SURFACE | ECE_INITAI));
        InfectedPilot.SetPosition(m_MissionPosition);
        //InfectedPilot.PlaceOnSurface();
        InfectedPilot.GetInventory().CreateAttachment("ZSh3PilotHelmet_Green");
        InfectedPilot.GetInventory().CreateInInventory("M67Grenade");
        InfectedPilot.GetInventory().CreateInInventory("CanOpener");
        InfectedPilot.GetInventory().CreateInInventory("BandageDressing");
        InfectedPilot.GetInventory().CreateInInventory("PeachesCan");
        InfectedPilot.GetInventory().CreateInInventory("Canteen");
        InfectedPilot.GetInventory().CreateAttachment("UKAssVest_Olive");
        InfectedPilot.GetInventory().CreateInInventory("PersonalRadio");
        InfectedPilot.GetInventory().CreateInInventory("Battery9V");
        InfectedPilot.GetInventory().CreateInInventory("Battery9V");
        InfectedPilot.GetInventory().CreateInInventory("Battery9V");

        //Pilot is dead
        InfectedPilot.SetHealth("", "", 0);

        m_MissionAIs.Insert(InfectedPilot);

        //Spawn horde
        for (int j = 0; j < HordeDensity; j++) {
            //calc new spawn position
            float x = Math.RandomFloatInclusive(3, 30);
            float y = Math.RandomFloatInclusive(3, 30);
            int Dice = Math.RandomIntInclusive(0, 9);
            if (Dice > 4) x *= -1.0;
            Dice = Math.RandomIntInclusive(0, 9);
            if (Dice < 5) y *= -1.0;
            vector NewPosVector = {
                x,
                0,
                y
            };

            //Spawn infected
            m_MissionAIs.Insert(GetGame().CreateObjectEx(InfectedTypes.GetRandomElement(), m_MissionPosition + NewPosVector, ECE_PLACE_ON_SURFACE | ECE_INITAI));
        }
    }

    override void ObjDespawn() {
        //nothing to despawn
    }

    override void MissionFinal() { //When player enters last mission target zone

        //Alert infected
        for (int j = 1; j < m_MissionAIs.Count(); j++) {
            DayZInfected Zed = DayZInfected.Cast(m_MissionAIs.Get(j));
            if (Zed) {
                DayZInfectedCommandMove moveCommandZ = Zed.GetCommand_Move();
                moveCommandZ.SetIdleState(2);
            }
        }

        //Finish mission
        m_RewardsSpawned = true;
        m_MsgNum = -1;
        m_MsgChkTime = m_MissionTime + MsgDlyFinish;
    }

    override void PlayerChecks(PlayerBase player) {

    }

    void UpdateBots(float dt) {

    }

    override bool DeployMission() { //When first player enters the mission zone (primary/secondary)
        if (m_MissionPosition && m_MissionPosition != "0 0 0") {
            //Call spawners
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnObjects);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SpawnAIs, 1000, false);
            return true;
        } else {
            Print("[SMM] ERROR : Mission position was rejected or doesn't exist. MissionPosition is NULL!");
            return false;
        }
    }
}
