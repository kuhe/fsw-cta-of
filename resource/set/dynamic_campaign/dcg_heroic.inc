{Heroic
	{GlobalMaxCP 500}
	{StageCP 50 60 70 80 90}
	{SpecialCP 50}					;// airstrikes special tab
	{EmplacementCP 50}				;// buildable with engineer
	{Bots
		{StartMP	0.05 min 100 attackerMultiplier 1.00}
		{FinishMP	2.00 attackerMultiplier 2}
		{CP
			{Base "0:0,300:65,450:70,600:75"} ;// seconds : CP
			{RoundMultiplier "0:0.6 2:0.8 4:0.9 6:1.0 8:1.1 12:1.2 14:1.3"} ;// games played : multiplier for CP
			{AttackMultiplier 100}
		}
		{DefenseLevel
			{level_1
				{DefenseBudgetPlayer	3.0}	;// budget it multiplied by number of flags
				{DefenseBudgetAI		3.0}	;// places defender units with bot StartMP * this factor (StartMP without attackermultiplier) for player side
				{unlock games 0 progress 0.0}	;// number of games to unlock this level, or progress in percent (campaign progress bar)
			}
			{level_2							;// once level is reached previous level values are ignored only currently level is used
				{DefenseBudgetPlayer	3.5}
				{DefenseBudgetAI		4.0}
				{unlock games 0 progress 0.4}
			}
			{level_3
				{DefenseBudgetPlayer	4.0}
				{DefenseBudgetAI		4.5}
				{unlock games 6 progress 0.6}
			}
		}
	}
	{PaybackFactor 0.3}		;// MP paid back when loosing solider, squad or vehicle
	{SellFactor 0.5}
	{ScavengedVehicleSellFactor 0.5}		;// captured enemy vehicle 
	{RiskFactor
		{Low
			{BotResources 1.0}
			{BotVeterancy 0}
			{Rewards 1.0}
		}
		{Standard
			{BotResources 1.0}
			{BotVeterancy 1}
			{Rewards 1.25}
		}
		{High
			{BotResources 1.0}
			{BotVeterancy 3}
			{Rewards 1.5}
		}
	}
	{Resources
		{Standard
			{MP ;// Manpower (generic money)
				{StartVal 800}
				{WinGain "1:200 4:250 6:300 8:350 10:400 12:600 14:800"} ;// games played : MP gain 
				{LoseGain "1:100"}
				{MapRewards	;//Bonus resources on various game types (a game can only be one randomly chosen type). Types: Airfield, Ammodepot, Bonus, Factory, Research.
					{Airfield	200}
					{Ammodepot	200}
					{Bonus		400}
					{Factory	300}
					{Research	200}
				}
			}
			{SP ;// Special Points (airstrikes)
				{StartVal 0}
				{WinGain 0}
				{LoseGain 0}
				{MapRewards
					{Airfield	5}
				}
			}
			{AP ;// Ammo points
				{StartVal 800}
				{WinGain "5:250 10:500 15:1000"}
				{LoseGain "1:100"}
				{MapRewards
					{Ammodepot	900}
					{Factory	500}
				}
			}
			{RP ;// Research points
				{StartVal 50}
				{WinGain 2}
				{LoseGain 1}
				{MapRewards
					{Bonus		1}
					{Research	3}
				}
			}
			{Budget
				{Start "0:100 4:110 8:120 12:130 16:140 20:150"} ;// games played : starting CP of each match 
				{PointsPerSecond 0.25} ;// CP income
				{Limit 350} ;// Max CP 
			}
		}
	}
	{Duration
		{Short
			{FlagCount "2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5"} ;// each entry is 1 game played. # of flags enabled : # of flags total on map
			{Bots
				{ResearchStages "0:2 1:2 2:3 3:4 4:5 5:5 6:6 7:6 8:7 9:7 10:8 11:8 12:9 13:9 14:10 15:11 16:12 17:13"} ;// number of games played : research tree level bots can have
			}
			{MapSelection "0:1"}	;// number of games played : map selection value from map .info file
			{MapBorder "0:1"}
		}
		{Normal
			{FlagCount "2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5"}
			{Bots
				{ResearchStages "0:2 1:2 2:3 3:4 4:5 5:5 6:6 7:6 8:7 9:7 10:8 11:8 12:9 13:9 14:10 15:11 16:12 17:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Long
			{FlagCount "2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5"}
			{Bots
				{ResearchStages "0:2 1:2 2:3 3:4 4:5 5:5 6:6 7:6 8:7 9:7 10:8 11:8 12:9 13:9 14:10 15:11 16:12 17:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{VeryLong
			{FlagCount "2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5"}
			{Bots
				{ResearchStages "0:2 1:2 2:3 3:4 4:5 5:5 6:6 7:6 8:7 9:7 10:8 11:8 12:9 13:9 14:10 15:11 16:12 17:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Unlimited
			{FlagCount "2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5"}
			{Bots
				{ResearchStages "0:2 1:2 2:3 3:4 4:5 5:5 6:6 7:6 8:7 9:7 10:8 11:8 12:9 13:9 14:10 15:11 16:12 17:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
	}
}