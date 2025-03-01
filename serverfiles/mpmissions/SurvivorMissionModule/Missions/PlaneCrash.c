class PlaneCrashMission extends SurvivorMissions {
    //Mission related entities
    Object CrashedC130;
    ItemBase MissionObject;

    //Mission parameters
    int MsgDlyFinish = 60; //seconds, message delay time after player has finished mission

    //Mission containers
    ref array < vector > ContainerSpawns = new array < vector > ;
    ref array < vector > InfectedSpawns = new array < vector > ;
    ref array < vector > FireSpawns = new array < vector > ;
    ref array < string > InfectedTypes = new array < string > ;

    //Mission variables
    string SurvivorName;

    override bool IsExtended() return false;

    void PlaneCrashMission() {
        //Mission mission timeout
        m_MissionTimeout = 2700; //seconds, mission duration time

        //Mission zones
        m_MissionZoneOuterRadius = 700.0; //meters (!Do not set lower than 200m), mission activation distance
        m_MissionZoneInnerRadius = 8.0; //meters (!Do not set outside of 1-5m), mission finishing distance to target object

        //Mission informant
        m_MissionInformant = "Dr. Legasov";

        //Mission person names
        SurvivorName = "Gerry Lane";

        //Set mission messages
        m_MissionMessage1 = "I just received a emergency call from a military pilot. One crew member was infected and suddenly attacked others. He said this flight has the highest international priority.";
        m_MissionMessage2 = "Also onboard is Mr. " + SurvivorName + ", he is an UN agent and it seems he has some information about the cure for this pandemic disease. They were at flight level 300 on their way to Wales.";
        m_MissionMessage3 = "The pilot said he was bitten and tried to emergency land somewhere in the fields\n** " + m_MissionLocationDir + " of " + m_MissionLocation + " **\nFind out if they made it. They have some rubles on board!";

        //Engine fire spawns
        FireSpawns.Insert("5.15 -2.18 -4.63"); //engine
        FireSpawns.Insert("5.15 -2.18 -5"); //engine
        FireSpawns.Insert("5.15 0 0"); //fire trace
        FireSpawns.Insert("4.8 0 0.5"); //fire trace
        FireSpawns.Insert("5.3 0 1"); //fire trace
        FireSpawns.Insert("5.15 0 15"); //fire trace
        FireSpawns.Insert("5.15 0 25"); //fire trace
        //FireSpawns.Insert("5.15 0 30");			//fire trace
        //FireSpawns.Insert("5.15 0 45");			//fire trace
        //FireSpawns.Insert("5.15 0 55");			//fire trace

        //Container spawnpoints
        ContainerSpawns.Insert("0.87 -4.5 -2.5");
        ContainerSpawns.Insert("0.87 -4.47 -0.5");

        //Infected spawnpoints
        InfectedSpawns.Insert("-10.5186 0 25.0269");
        InfectedSpawns.Insert("24.9775 0 -10.4146");
        InfectedSpawns.Insert("-30.1726 0 -6.2729");
        InfectedSpawns.Insert("-20.9209 0 4.6636");
        InfectedSpawns.Insert("15.0283 0 -10.3276");
        InfectedSpawns.Insert("7.2461 0 30.5884");
        InfectedSpawns.Insert("-20.6855 0 5.9956");
        InfectedSpawns.Insert("40 0 20");
        InfectedSpawns.Insert("-20 0 -40");
        InfectedSpawns.Insert("-50 0 50");
        InfectedSpawns.Insert("35 0 40");
        InfectedSpawns.Insert("-40 0 -20");
        InfectedSpawns.Insert("-30 0 -40");

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

    void ~PlaneCrashMission() {
        //Despawn all remaining mission objects
        if (m_MissionObjects) {
            Print("[SMM] Despawning " + m_MissionObjects.Count() + " mission objects from old mission...");
            for (int i = 0; i < m_MissionObjects.Count(); i++) {
                if (!m_MissionObjects.Get(i)) continue;
                else GetGame().ObjectDelete(m_MissionObjects.Get(i));
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

    void ExplodeWreck(int count) {
        for (int n = 0; n < count; n++) {
            Grenade_Base Explosives = Grenade_Base.Cast(GetGame().CreateObject("M67Grenade", CrashedC130.ModelToWorld("5.15 -2.28 -4.63")));
            Explosives.ActivateImmediate();
        }

    }
    void SpawnObjects() {
        //Spawn crashed plane crashed C130
        int PlaneOriConversion;
        string PlaneOrientation;

        PlaneOriConversion = m_MissionDescription[3].ToInt() - 180;
        if (PlaneOriConversion < 0) PlaneOriConversion += 360;
        PlaneOrientation = PlaneOriConversion.ToString() + " 0 0";

        CrashedC130 = GetGame().CreateObjectEx("Land_Wreck_C130J", m_MissionPosition, ECE_PLACE_ON_SURFACE);
        CrashedC130.SetOrientation(PlaneOrientation.ToVector());
        CrashedC130.PlaceOnSurface();
        m_MissionObjects.Insert(CrashedC130);

        //Enginefire
        for (int s = 0; s < FireSpawns.Count(); s++) {
            FireplaceBase Enginefire;

            if (s > 1) {
                vector posXZ = CrashedC130.ModelToWorld(FireSpawns.Get(s));
                float x = posXZ[0];
                float z = posXZ[2];
                float y = GetGame().SurfaceY(x, z);
                vector Groundpos = {
                    x,
                    y,
                    z
                };

                Enginefire = FireplaceBase.Cast(GetGame().CreateObjectEx("Fireplace", Groundpos, ECE_PLACE_ON_SURFACE));
                Enginefire.SetPosition(Groundpos - "0 0.3 0");
            } else
                Enginefire = FireplaceBase.Cast(GetGame().CreateObjectEx("Fireplace", CrashedC130.ModelToWorld(FireSpawns.Get(s)), ECE_PLACE_ON_SURFACE));

            Enginefire.Synchronize();
            Enginefire.GetInventory().CreateAttachment("Firewood");
            Enginefire.GetInventory().CreateAttachment("WoodenStick");
            Enginefire.GetInventory().CreateAttachment("Rag");
            Enginefire.StartFire(true);
            m_MissionObjects.Insert(Enginefire);
        }

        //Create smoke on destroyed engine
        Object EngineSmoke = GetGame().CreateObjectEx("Wreck_UH1Y", CrashedC130.ModelToWorld("5.15 -7 -3.63"), ECE_PLACE_ON_SURFACE);
        m_MissionObjects.Insert(EngineSmoke);

        //Explosion at planecrash time delayed
        //ExplodeWreck(3);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.ExplodeWreck, 800, false, 6);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.ExplodeWreck, 1400, false, 5);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.ExplodeWreck, 1800, false, 6);

        //Spawn containers
        int selectedLoadout;

        for (int i = 0; i < ContainerSpawns.Count(); i++) {
            MissionObject = ItemBase.Cast(GetGame().CreateObjectEx("Bear_Pink", CrashedC130.ModelToWorld(ContainerSpawns.Get(i)), ECE_PLACE_ON_SURFACE));

            //Get random loadout
            selectedLoadout = Math.RandomIntInclusive(0, 9); //!change randomization limit after adding new loadouts!

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
                MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
                MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
                MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
                MissionObject.GetInventory().CreateInInventory("TraderPlus_Money_Ruble2_Coin");
            }

            Print("[SMM] Mission rewards spawned in reward container" + i + ". Randomly selected loadout was " + selectedLoadout + ".");

            //Insert mission container into mission objects list
            m_MissionObjects.Insert(MissionObject);
        }

        Print("[SMM] Survivor Mission " + m_selectedMission + " :: " + m_MissionName + " ...mission deployed!");
    }

    void SpawnAIs() {
        //Spawn infected pilot
        vector InfectedPos = CrashedC130.ModelToWorld("3 0 -9");
        m_MissionAIs.Insert(GetGame().CreateObjectEx("ZmbM_CommercialPilotOld_Olive", InfectedPos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
        DayZInfected InfectedSurvivor = DayZInfected.Cast(m_MissionAIs[0]);
        InfectedSurvivor.GetInventory().CreateAttachment("ZSh3PilotHelmet_Green");
        InfectedSurvivor.GetInventory().CreateAttachment("UKAssVest_Olive");
        InfectedSurvivor.GetInventory().CreateInInventory("Glock19");
        InfectedSurvivor.GetInventory().CreateInInventory("Mag_Glock_15Rnd");
        InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
        InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
        InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");

        InfectedSurvivor.SetHealth("", "", 15);

        //Spawn infected
        for (int j = 0; j < InfectedSpawns.Count(); j++) {
            string RandomInfected = InfectedTypes.GetRandomElement();
            vector InfectedPos1 = CrashedC130.ModelToWorld(InfectedSpawns.Get(j));
            m_MissionAIs.Insert(GetGame().CreateObjectEx(RandomInfected, InfectedPos1, ECE_PLACE_ON_SURFACE | ECE_INITAI));
        }
    }

    override void ObjDespawn() {
        //Despawn nothing
    }

    override void MissionFinal() { //When player enters last mission target zone
        //Respawn some infected
        for (int m = 0; m < InfectedSpawns.Count(); m++) {
            string RandomInfected = InfectedTypes.GetRandomElement();
            vector InfectedPos = CrashedC130.ModelToWorld(InfectedSpawns.Get(m));
            m_MissionAIs.Insert(GetGame().CreateObjectEx(RandomInfected, InfectedPos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
        }

        //Finish mission
        m_RewardsSpawned = true;
        m_MsgNum = -1;
        m_MsgChkTime = m_MissionTime + MsgDlyFinish;
    }

    override void PlayerChecks(PlayerBase player) {
        //nothing to check
    }

    void UpdateBots(float dt) {
        //no bots involved in this mission
    }

    override bool DeployMission() { //When first player enters the mission zone (primary/secondary)
        if (m_MissionPosition && m_MissionPosition != "0 0 0") {
            //Call spawners
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnObjects);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnAIs);
            return true;
        } else {
            Print("[SMM] ERROR : Mission position was rejected or doesn't exist. MissionPosition is NULL!");
            return false;
        }
    }
}
