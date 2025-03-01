class BearHuntMission extends SurvivorMissions {
    //Mission related entities
    ItemBase MissionObject;
    Object MissionBuilding;

    //Mission parameters
    int ReqMeatAmount = 4; //pieces, requested mushroom amount
    int ExtendedTimout = 1800; //seconds, mission duration time for extended mission
    int MsgDlyFinish = 60; //seconds, message delay time after player has finished mission

    //Mission containers
    ref array < vector > ExtendedPosList = new array < vector > ;
    ref array < vector > Spawnpoints = new array < vector > ;
    ref array < vector > InfectedSpawns = new array < vector > ;
    ref array < string > InfectedTypes = new array < string > ;

    //Mission variables
    string SurvivorName;

    override bool IsExtended() return true;

    void BearHuntMission() {
        //Select primary mission
        m_MissionExtended = true;

        //Mission timeout
        m_MissionTimeout = 2700; //seconds, mission max duration time

        //Mission zones
        m_MissionZoneOuterRadius = 80.0; //meters (!Do not set lower than 200m), mission activation distance
        m_MissionZoneInnerRadius = 3.0; //meters (!Do not set outside of 1-5m), mission finishing distance to target object

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
            "Nikolai"
        };
        SurvivorName = SurvivorNames.GetRandomElement();

        //Set mission messages for primary mission
        m_MissionMessage1 = "A survivor recently reported to me that a bear attacked my friend " + SurvivorName + " and killed 2 other survivor's. They went to the wrong location trying to hunt some deer in the forest of " + m_MissionLocation + ".";
        m_MissionMessage2 = "I still can't believe it. " + SurvivorName + " was one of the best hunters araound here. Once a week he brought fresh meat to the hidden camp to feed the survivor's. He was never selfless and tried to do everything to help out in the camp.";
        m_MissionMessage3 = "The bear was last reported at the forest near\n** " + m_MissionLocationDir + " of " + m_MissionLocation + " **\nI want you to kill this animal and take his pelt. It's not for revenge, we just need the pelt to make winter clothing for the kids. Be careful!";

        //Spawnpoint for MissionObject for secondary mission
        Spawnpoints.Insert("-18.40 2.19 18.57");

        //Infected spawnpoints for secondary mission
        InfectedSpawns.Insert("-7.46 -4.94 -12.99");
        InfectedSpawns.Insert("-15.65 -4.93 -22.08");
        InfectedSpawns.Insert("-22.5 -4.93 1.95");
        InfectedSpawns.Insert("-21.93 -4.93 13.0");
        InfectedSpawns.Insert("-17.95 -4.93 21.84");
        InfectedSpawns.Insert("-6.77 -4.89 21.28");
        InfectedSpawns.Insert("-21.14 -1.83 -5.83");
        InfectedSpawns.Insert("-10.5 1.27 -22.22");
        //...outside MissionBuilding
        InfectedSpawns.Insert("0.23 -5.52 3.55");
        InfectedSpawns.Insert("19.78 -5.52 -5.66");

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
    }

    void ~BearHuntMission() {
        //Despawn all remaining objects
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

    void SpawnContainer() {
        MissionObject = ItemBase.Cast(GetGame().CreateObjectEx("HuntingBag", m_MissionPosition, ECE_PLACE_ON_SURFACE));
        m_MissionObjects.InsertAt(MissionObject, 0);
    }

    void SpawnRewards() {
        //new MissionObject after deleting protector case
        MissionObject = ItemBase.Cast(GetGame().CreateObjectEx("Bear_Pink", m_MissionPosition, ECE_PLACE_ON_SURFACE));

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
            //Spawn no objects at primary mission
        } else {
            if (MissionBuilding) {
                //Cleanup position before spawning protector case
                GetGame().GetObjectsAtPosition(m_MissionPosition, 0.5, m_ObjectList, m_ObjectCargoList);
                for (int k = 0; k < m_ObjectList.Count(); k++) {
                    Object FoundObject = m_ObjectList.Get(k);
                    if (FoundObject.IsItemBase())
                        GetGame().ObjectDelete(FoundObject);
                }

                //Spawn container
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SpawnContainer, 1000);

                Print("[SMM] Survivor Mission Extension " + m_selectedMission + " :: " + m_MissionName + " ...mission extended!");
            } else Print("[SMM] Extended MissionBuilding couldn't be found in " + m_MissionDescription[3] + " ... Mission rejected!");
        }
    }

    void SpawnAIs() {
        if (m_MissionExtended) {
            //Spawn Bear at primary mission
            m_MissionAIs.Insert(GetGame().CreateObjectEx("Animal_UrsusArctos", m_MissionPosition, ECE_PLACE_ON_SURFACE | ECE_INITAI));

            Print("[SMM] Survivor Mission " + m_selectedMission + " :: " + m_MissionName + " ...mission deployed!");
        } else {
            if (MissionBuilding) {
                //Spawn some infected at school
                for (int j = 0; j < InfectedSpawns.Count(); j++) {
                    string RandomInfected = InfectedTypes.GetRandomElement();
                    vector InfectedPos = MissionBuilding.ModelToWorld(InfectedSpawns.Get(j));
                    DayZInfected Zed = DayZInfected.Cast(GetGame().CreateObjectEx(RandomInfected, InfectedPos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
                    m_MissionAIs.Insert(Zed);
                }
            }
        }
    }

    override void ObjDespawn() {
        //Despawn nothing
    }

    override void ExtendMission() {
        //Set new mission messages
        m_MissionMessage1 = "Allright survivor, you have found the bear location. Try to safely engage and kill him by aiming at his head or heart. A bear is a strong animal, so it will take some shots to get him down.";
        m_MissionMessage2 = "Take out your knife and eviscerate him. Bring the pelt and the meat to the\n** " + m_MissionSecondaryLoc + " School laboratory class room **\n(left wing, top floor) because I want to examine the bear meat. I left a hunting bag on the labor desk.";
        m_MissionMessage3 = "Put atleast " + ReqMeatAmount + " bear steaks and the pelt in there. Be carefull, there might be bandits around which could intercepted our little radio talk here. Good luck!";

        //init Messenger for new messages
        m_MsgNum = 1; //skip msg 0, begin with msg 1
        m_MsgChkTime = m_MissionTime;
        MsgCutoff = false;

        //increase mission MissionTimeout
        m_MissionTimeout = m_MissionTime + ExtendedTimout;

        //deployment settings & init for extended mission
        m_MissionZoneOuterRadius = 120.0;
        m_MissionZoneInnerRadius = 2.0;

        //Get building position from building type and location
        if (EventsWorldData.GetBuildingsAtLoc("Land_City_School", m_MissionDescription[3], ExtendedPosList)) {
            //Get MissionPosition for MissionBuilding from secondary mission
            m_MissionPosition = ExtendedPosList.GetRandomElement();
            GetGame().GetObjectsAtPosition(m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList);
            for (int m = 0; m < m_ObjectList.Count(); m++) {
                Object FoundObject = m_ObjectList.Get(m);
                if (FoundObject.GetType() == "Land_City_School") {
                    MissionBuilding = FoundObject;

                    //new MissionPosition is rewards spawnpoint
                    m_MissionPosition = MissionBuilding.ModelToWorld(Spawnpoints.Get(0));
                    break;
                }
            }
        } else Print("[SMM] Can't find MissionBuilding City School in " + m_MissionDescription[3] + "!");
    }

    override void MissionFinal() { //When player enters last mission target zone
        //Spawn infected
        string RandomInfected;
        vector InfectedPos;

        for (int k = 0; k < InfectedSpawns.Count(); k++) {
            RandomInfected = InfectedTypes.GetRandomElement();
            InfectedPos = MissionBuilding.ModelToWorld(InfectedSpawns.Get(k));
            m_MissionAIs.Insert(GetGame().CreateObjectEx(RandomInfected, InfectedPos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
        }

    }

    override void PlayerChecks(PlayerBase player) {
        //Update Bear position
        if (m_MissionExtended) {
            Object Bear = Object.Cast(m_MissionAIs[0]);
            if (Bear && Bear.ClassName() == "Animal_UrsusArctos")
                m_MissionPosition = Bear.GetPosition();
        }

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

        //Check if container has desired amount of mushrooms collected at primary mission position
        if (MissionObject && MissionObject.ClassName() == "HuntingBag" && !m_MissionExtended) {
            int CargoCount = MissionObject.GetInventory().CountInventory();
            int LastCount = 0;
            int FoundMeatObjects = 0;
            bool FoundPeltObject = false;

            if (CargoCount != LastCount) {
                if (CargoCount >= ReqMeatAmount && FoundMeatObjects <= ReqMeatAmount) {
                    CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();

                    for (int i = 0; i < CargoCount; i++) {
                        EntityAI CargoItem = CargoItems1.GetItem(i);
                        if (CargoItem && CargoItem.GetType() == "BearSteakMeat") FoundMeatObjects++;
                        else if (CargoItem && CargoItem.GetType() == "BearPelt") FoundPeltObject = true;
                        else continue;

                        //When requested amount of mushrooms is present, despawn MissionObject & spawn rewards
                        if (FoundMeatObjects >= ReqMeatAmount && FoundPeltObject) {
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
        //Get MissionBuilding at mission position
        if (!m_MissionExtended && !MissionBuilding) {
            if (EventsWorldData.GetBuildingsAtLoc("Land_City_School", m_MissionDescription[3], ExtendedPosList)) {
                //Get MissionPosition for MissionBuilding from secondary mission
                m_MissionPosition = ExtendedPosList.GetRandomElement();
                GetGame().GetObjectsAtPosition(m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList);
                for (int m = 0; m < m_ObjectList.Count(); m++) {
                    Object FoundObject = m_ObjectList.Get(m);
                    if (FoundObject.GetType() == "Land_City_School") {
                        MissionBuilding = FoundObject;
                        Print("[SMM] MissionBuilding extended is " + MissionBuilding.GetType() + " at " + m_MissionDescription[3] + " @ " + MissionBuilding.GetPosition());

                        //new MissionPosition is rewards spawnpoint
                        m_MissionPosition = MissionBuilding.ModelToWorld(Spawnpoints.Get(0));
                        break;
                    }
                }
            } else Print("[SMM] Can't find MissionBuilding City School in " + m_MissionDescription[3] + "!");
        }

        if ((m_MissionPosition && m_MissionPosition != "0 0 0" && m_MissionExtended) || (MissionBuilding && !m_MissionExtended)) {
            //Call spawners
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnObjects);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnAIs);
            return true;
        } else {
            Print("[SMM] Mission position was rejected or MissionBuilding doesn't exist!");
            if (MissionSettings.DebugMode && !MissionBuilding && !m_MissionExtended) Print("[SMM] MissionBuilding is NULL!");
            return false;
        }
    }
}
