; == mid WAR STANDARD RESOURCES ==
(define "standard_all"
	{common
		{unitset
			{value "mid^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		{unitLimits "officer=1;flamer=3;sniper=3;squad_1=5;squad_4=5;limit1=1;limit2=2;limit3=3;limit4=4;limit5=5;limit10=10"}
		{chargeFactors
			{value "*=1.00"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	2400}		; in seconds
					{growTable	"0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.82 0.84 0.86 0.88 0.9 0.90 0.9 0.85 0.8 0.75 0.7"}
					{payback
						{cp			"0		20		50		80		100		300"} ; keep only 6 values
						{restore	"1.00	1.00	0.5 	0.25	0.10	0.05"}
					}
				}
				{buttons "inf1 inf2 empl vehicles tanks"}
			}
			{hero
				{resource 
					{start 100}
				} 
				{buttons "doctrine"}
				{tag "special"}
			}
		}
	}
	{bots
		(include "bots_generic.inc")
		("deploy_bots" period("mid"))
	}
)

; == mid WAR CUSTOM RESOURCES ==
(define "custom_all"
	{common
		{unitset
			{value "mid^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		{unitLimits "officer=1;flamer=3;sniper=3;medic=5"}
		{chargeFactors
			{value "*=1.00"}
			{customize "0;0.25;0.5;1;2"}
		}
		{budgets
			{vehicle
				{mode "custom"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	2400}		; in seconds
					{growTable	"0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.82 0.84 0.86 0.88 0.9 0.90 0.9 0.85 0.8 0.75 0.7"}
					{payback
						{cp			"0		20		50		80		100		120"} ; keep only 6 values
						{restore	"1.00	1.00	0.5 	0.25	0.10	0.05"}
					}
					{limitmin	1000}
					{limitmax	50000}
					{speedset	"2500 3000 3500 4000 4500 5000 8000 10000 15000 20000"}
				}
				{buttons "inf1 inf2 empl vehicles tanks"}
			}
			{hero
				{resource 
					{start 	100}
				} 
				{buttons "doctrine"}
				{tag "special"}
			}
		}
	}
	{bots
		(include "bots_generic.inc")
		("deploy_bots" period("mid"))
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:mid_standard_100"
		{gameMode "standard"}
		{unitMode "mid"}
		{specMode "all_normal"}
		{apply "only_roster_mid"}
		("standard_all"			start(200) finish(3500) cp(0:100,900:125,1500:150))
		{ranked}
	}
;------------------------------------------------------------------------------------------------------------	

	{"c:mid_custom_100"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_100"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(3500) cp(0:100,900:125,1500:150))
	}
	{"c:mid_custom_120"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_120"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(4000) cp(0:120,900:145,1500:170))
	}
	{"c:mid_custom_140"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_140"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(4500) cp(0:140,900:165,1500:190))
	}
	{"c:mid_custom_160"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_160"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(5000) cp(0:160,900:185,1500:210))
	}
	{"c:mid_custom_180"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_180"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(5500) cp(0:180,900:210,1500:230))
	}
	{"c:mid_custom_200"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_200"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(6000) cp(0:200,900:250,1500:300))
	}
	{"c:mid_custom_250"
		{gameMode "custom"}
		{unitMode "mid"}
		{specMode "cp_250"}
		{apply "only_roster_mid"}
		("custom_all"			start(200) finish(6500) cp(0:250,900:300,1500:350))
	}
;------------------------------------------------------------------------------------------------------------
}