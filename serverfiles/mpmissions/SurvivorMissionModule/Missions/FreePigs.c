class FreePigsMission extends SurvivorMissions {
    //Mission related entities
    Car MissionCar;
    Object MissionBuilding;
    ItemBase MissionObject;

    //Mission parameters
    int ReqMeatAmount = 14; //pieces, mission ganja (equivalent to x * 4 gramms)
    int ExtendedTimout = 1500; //seconds, mission duration time for extended mission
    int MsgDlyFinish = 60; //seconds, message delay time after player has finished mission

    //Mission containers
    ref array < vector > ExtendedPosList = new array < vector > ;
    ref array < vector > Spawnpoints = new array < vector > ;
    ref array < vector > PriInfectSpawns = new array < vector > ;
    ref array < vector > SecInfectSpawns = new array < vector > ;
    ref array < string > InfectedTypes = new array < string > ;
    ref array < vector > CagedPigSpawns = new array < vector > ;

    //Mission variables
    string SurvivorName;
    vector RewardsPosition = "0.84 -0.75 0.16";
    vector TargetPosition = "-1.74 -3.01 0.49";

    override bool IsExtended() return true;

    void FreePigsMission() {
        //Select primary mission
        m_MissionExtended = true;

        //Mission timeout
        m_MissionTimeout = 2700; //seconds, primary mission duration time

        //Mission zones
        m_MissionZoneOuterRadius = 150.0; //meters (!Do not set lower than 200m), mission activation distance
        m_MissionZoneInnerRadius = 6.0; //meters (!Do not set outside of 1-5m), mission finishing distance to target object

        //Mission informant
        m_MissionInformant = "Dr. Legasov";

        //Mission person names
        TStringArray SurvivorNames = {
            "Yuri",
            "Michail",
            "Boris",
            "Valeri",
            "Anatoli",
            "Ivan",
            "Alexej",
            "Dimitrij",
            "Sergej",
            "Nikolai",
            "Vladimir"
        };
        SurvivorName = SurvivorNames.GetRandomElement();

        //Set mission messages for primary mission
        m_MissionMessage1 = SurvivorName + ", a farmer from " + m_MissionLocation + ", died 2 days ago after a attack from bandits. He was protecting his animals from infected and scavengers and was farming pigs to deliver meat to the young and old survivors hideout somewhere in the forests.";
        m_MissionMessage2 = "He was well known under survivors for his perfection in making good bacon and spiced meat for barbecue. His pigs are still in the shed and I am afraid they could starve to death, if they are not already dead by infected or robbed by bandits.";
        m_MissionMessage3 = "Go to " + SurvivorName + "'s farm located \n** " + m_MissionLocationDir + " of " + m_MissionLocation + " **\nand free all the pigs from their cage to give them a chance to survive. You need at least a knife.";

        //Spawnpoints for caged pigs in farm (view from inside building at door position)
        //right cage row
        CagedPigSpawns.Insert("0.92 -3.01 3.10");
        CagedPigSpawns.Insert("-0.49 -3.01 3.10");
        CagedPigSpawns.Insert("-4.72 -3.01 3.10");
        CagedPigSpawns.Insert("-6.13 -3.01 3.10");
        //left cage row
        CagedPigSpawns.Insert("-7.42 -3.01 -2.21");
        //next building part of shed left
        CagedPigSpawns.Insert("7.78 -3.04 2.85");
        CagedPigSpawns.Insert("6.28 -3.04 2.85");

        //Spawnpoints for MissionObjects in middle garage (Do not change order!)
        Spawnpoints.Insert("0.249 -3.01 -3.24"); //at left door to chicken room (Wellies)

        //Infected spawnpoints for primary mission
        PriInfectSpawns.Insert("-30 0 -10");
        PriInfectSpawns.Insert("-35 0 -13");
        PriInfectSpawns.Insert("-40 0 -9");
        PriInfectSpawns.Insert("-45 0 -15");
        PriInfectSpawns.Insert("-30 0 10");
        PriInfectSpawns.Insert("-35 0 13");
        PriInfectSpawns.Insert("-40 0 9");
        PriInfectSpawns.Insert("-45 0 15");

        //Infected spawnpoints for secondary mission
        SecInfectSpawns.Insert("-11 0 -7");
        SecInfectSpawns.Insert("-8 0 8");
        SecInfectSpawns.Insert("8 0 -9");
        SecInfectSpawns.Insert("6 0 -5");
        SecInfectSpawns.Insert("18 0 15");

        //Infected types for secondary mission position
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

        //Search for mission building at primary mission position
        GetGame().GetObjectsAtPosition(m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList);
        for (int i = 0; i < m_ObjectList.Count(); i++) {
            Object FoundObject = m_ObjectList.Get(i);
            if (FoundObject.GetType() == "Land_Farm_CowshedA") {
                MissionBuilding = FoundObject;
                Print("[SMM] MissionBuilding is " + MissionBuilding.GetType() + " at " + m_MissionDescription[2] + " of " + m_MissionDescription[1] + " @ " + MissionBuilding.GetPosition());
                break;
            }
        }
        if (!MissionBuilding) Print("[SMM] Farm couldn't be found. Mission rejected!");
        else {
            //Close all farm doors
            Building farm = Building.Cast(MissionBuilding);
            for (int j = 0; j < 5; j++)
                if (farm.IsDoorOpen(j)) farm.CloseDoor(j);

            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 1000, false, farm);
        }
    }

    void ~FreePigsMission() {
        //Despawn all remaining mission objects
        if (m_MissionObjects) {
            Print("[SMM] Despawning " + m_MissionObjects.Count() + " mission objects from old mission...");
            for (int i = 0; i < m_MissionObjects.Count(); i++) {
                if (!m_MissionObjects.Get(i)) continue;
                else GetGame().ObjectDelete(m_MissionObjects.Get(i));
            }
            m_MissionObjects.Clear();
        }

        //Delete mission AI's
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

    void SpawnRewards() {
        //new MissionObject after deleting hunting bag
        MissionObject = ItemBase.Cast(GetGame().CreateObjectEx("Bear_Pink", m_MissionPosition, ECE_PLACE_ON_SURFACE));
        MissionObject.SetPosition(m_MissionPosition);

        //Get random loadout
        int selectedLoadout = Math.RandomIntInclusive(0, 9); //!change randomization limit after adding new loadouts!

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

        Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was " + selectedLoadout + ".");
    }

    void SpawnObjects() {
        if (m_MissionExtended) {
            //New MissionPosition is at first cages in farm building
            m_MissionPosition = MissionBuilding.ModelToWorld(TargetPosition);

            //Spawn farmer loot
            m_MissionObjects.Insert(GetGame().CreateObjectEx("Wellies_Green", MissionBuilding.ModelToWorld(Spawnpoints.Get(0)), ECE_PLACE_ON_SURFACE));

            Print("[SMM] Survivor Mission " + m_selectedMission + " :: " + m_MissionName + " ...primary mission deployed!");
        } else {
            //New MissionPosition is hiking rest table
            m_MissionPosition = MissionBuilding.ModelToWorld(RewardsPosition);

            //Spawn mission target huntig bag
            MissionObject = ItemBase.Cast(GetGame().CreateObjectEx("HuntingBag", m_MissionPosition, ECE_PLACE_ON_SURFACE));
            MissionObject.SetPosition(m_MissionPosition);
            MissionObject.SetOrientation(MissionBuilding.GetOrientation() + "-90 -25 0");
            m_MissionObjects.InsertAt(MissionObject, 0);

            Print("[SMM] Survivor Mission Extension " + m_selectedMission + " :: " + m_MissionName + " ...secondary mission deployed!");
        }
    }

    void SpawnAIs() {
        int PigPosCount;
        string RandomInfected;
        vector InfectedPos;
        vector PigPos;
        DayZInfected Zed;
        Object Pig;
        Object MissionBuilding2;

        if (!MissionBuilding) Print("[SMM] Extended Mission : Missionbuilding couldn't be found in " + m_MissionDescription[3] + ".");
        else {
            if (m_MissionExtended) {
                //Search for second farm building part
                GetGame().GetObjectsAtPosition(MissionBuilding.ModelToWorld("-19.54 0 0"), 1.5, m_ObjectList, m_ObjectCargoList);
                for (int i = 0; i < m_ObjectList.Count(); i++) {
                    Object FoundObject = m_ObjectList.Get(i);
                    if (FoundObject.GetType() == "Land_Farm_CowshedB") {
                        Print("[SMM] Second farm building found.");
                        MissionBuilding2 = FoundObject;
                        PigPosCount = CagedPigSpawns.Count();
                        break;
                    }
                }

                if (!MissionBuilding2) {
                    Print("[SMM] No second farm building found");
                    PigPosCount = 5;
                }

                //Spawn caged pigs in farm
                for (int j = 0; j < PigPosCount; j++) {
                    if (j < 5)
                        PigPos = MissionBuilding.ModelToWorld(CagedPigSpawns.Get(j));
                    else PigPos = MissionBuilding2.ModelToWorld(CagedPigSpawns.Get(j));

                    Pig = GetGame().CreateObjectEx("Animal_SusDomesticus", PigPos, ECE_PLACE_ON_SURFACE | ECE_INITAI);
                    Pig.SetPosition(PigPos);
                    m_MissionAIs.Insert(Pig);
                }

                //Spawn a hen (stays on server til restart)
                GetGame().CreateObjectEx("Animal_GallusGallusDomesticus", MissionBuilding.ModelToWorld("6.8 -3.01 -5.76"), ECE_PLACE_ON_SURFACE | ECE_INITAI);
            } else {
                //Spawn some infected at hiking rest
                for (int k = 0; k < SecInfectSpawns.Count(); k++) {
                    RandomInfected = InfectedTypes.GetRandomElement();
                    InfectedPos = MissionBuilding.ModelToWorld(SecInfectSpawns.Get(k));
                    Zed = DayZInfected.Cast(GetGame().CreateObjectEx(RandomInfected, InfectedPos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
                    m_MissionAIs.Insert(Zed);
                }
            }
        }
    }

    override void ObjDespawn() {
        //Despawn nothing
    }

    override void ExtendMission() { //When player enters mission target zone at primary mission

        //init Messenger for new messages
        m_MsgNum = 1; //skip msg 0, begin with msg 1
        m_MsgChkTime = m_MissionTime;
        MsgCutoff = false;

        //increase mission MissionTimeout for secondary mission
        m_MissionTimeout = m_MissionTime + ExtendedTimout;

        //deployment settings & init for secondary mission
        m_MissionZoneOuterRadius = 120.0;
        m_MissionZoneInnerRadius = 2.0;

        //Get secondary mission position
        if (EventsWorldData.GetBuildingsAtLoc("Land_Misc_TrailRoof_Small", m_MissionDescription[3], ExtendedPosList))
            m_MissionPosition = ExtendedPosList.GetRandomElement();
        else Print("[SMM] Can't get secondary MissionPosition in " + m_MissionDescription[3] + " from EventsWorldData!");

        string Coords = Math.Round(m_MissionPosition[0]).ToString() + " / " + Math.Round(m_MissionPosition[2]).ToString();

        //Set messages for secondary mission,
        m_MissionMessage1 = "Allright, you have found the pigs. Herd them all out of the shed. Protect them from infected attacks and kill 2 pigs to get some meat.";
        m_MissionMessage2 = "A man from the survivor camp said he could go to a save position anywhere in the forests and get the meat. I left a hunting bag at the picnic table on the hiking trail.";
        m_MissionMessage3 = "Bring the meat to the picnic table near\n** " + m_MissionSecondaryLoc + ", coordinates: " + Coords + " **\nPut " + ReqMeatAmount + " pig steaks inside it and then you can take what you need. Be careful!";

        //Search for mission building at old mission position
        GetGame().GetObjectsAtPosition(m_MissionPositions.Get(m_selectedMission), 1.0, m_ObjectList, m_ObjectCargoList);
        for (int i = 0; i < m_ObjectList.Count(); i++) {
            Object FoundObject = m_ObjectList.Get(i);
            if (FoundObject.GetType() == "Land_Farm_CowshedA") {
                Object Farm = FoundObject;
                //Spawn some infected at farm
                for (int j = 0; j < PriInfectSpawns.Count(); j++) {
                    string RandomInfected = InfectedTypes.GetRandomElement();
                    vector InfectedPos = Farm.ModelToWorld(PriInfectSpawns.Get(j));
                    DayZInfected Zed = DayZInfected.Cast(GetGame().CreateObjectEx(RandomInfected, InfectedPos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
                    m_MissionAIs.Insert(Zed);
                }

                break;
            }
        }
    }

    override void MissionFinal() { //When player enters last mission target zone
        //do nothing
    }

    override void PlayerChecks(PlayerBase player) {
        //Check if container gets taken from player
        if (MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended) {
            if (m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "HuntingBag") {
                if (player.GetInventory().HasEntityInInventory(EntityAI.Cast(m_MissionObjects[0])) && !m_ContainerWasTaken) {
                    m_ContainerWasTaken = true;
                    Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
                    GetGame().ObjectDelete(m_MissionObjects[0]);
                }
            }
        }

        //Check if container has desired amount of steaks collected at primary mission position
        if (MissionObject && MissionObject.ClassName() == "HuntingBag" && !m_MissionExtended) {
            int CargoCount = MissionObject.GetInventory().CountInventory();
            int LastCount = 0;
            int FoundObjects;

            if (CargoCount != LastCount) {
                FoundObjects = 0;

                if (CargoCount >= ReqMeatAmount) {
                    CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();

                    for (int i = 0; i < CargoCount; i++) {
                        EntityAI CargoItem = CargoItems1.GetItem(i);
                        if (CargoItem && CargoItem.GetType() == "PigSteakMeat") FoundObjects++;
                        else continue;

                        //When requested amount of mushrooms is present, despawn MissionObject & spawn rewards
                        if (FoundObjects >= ReqMeatAmount) {
                            Print("[SMM] Player with SteamID64: " + player.GetIdentity().GetPlainId() + " has successfully stored the requested amount of " + ReqMeatAmount + " MissionObjects in the container.");
                            //delete container first
                            GetGame().ObjectDelete(MissionObject);
                            //call rewards spawn one second later
                            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SpawnRewards, 1000);
                            m_RewardsSpawned = true;
                            m_MsgNum = -1;
                            m_MsgChkTime = m_MissionTime + MsgDlyFinish;
                            break;
                        }
                    }

                    LastCount = CargoCount;
                }
            }
        }
    }

    void UpdateBots(float dt) {
        //No bots involved in this mission
    }

    override bool DeployMission() { //When first player enters the mission zone (primary/secondary)
        //Get MissionBuilding at secondary mission position
        if (!m_MissionExtended) {
            GetGame().GetObjectsAtPosition(m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList);
            for (int i = 0; i < m_ObjectList.Count(); i++) {
                Object FoundObject = m_ObjectList.Get(i);
                if (FoundObject.GetType() == "Land_Misc_TrailRoof_Small") {
                    MissionBuilding = FoundObject;
                    Print("[SMM] MissionBuilding extended is " + m_MissionDescription[3] + " Hiking Rest @ " + m_MissionPosition);

                    //new MissionPosition is rewards spawnpoint
                    m_MissionPosition = MissionBuilding.ModelToWorld(RewardsPosition);
                    break;
                }
            }
        }

        if (MissionBuilding) {
            //Call spawners
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnObjects);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnAIs);
            return true;
        } else {
            Print("[SMM] ERROR : MissionBuilding can't be found!");
            if (MissionSettings.DebugMode) Print("[SMM] MissionBuilding is NULL!");
            return false;
        }
    }
}
