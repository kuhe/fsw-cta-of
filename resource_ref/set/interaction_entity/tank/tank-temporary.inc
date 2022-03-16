
	;/*=========== Fuel Burn/Explosion Chances Begin ===========*/

	{##on "fuel_leak"
		{if not "fuel_fire"
			{if rand 0.6
				{delay 2.5 2.5
					{add_view	"smoke_dead_norm"	"burn_fire"	"FXfire1"}
					{view start "smoke_fuel"}
					{call "engine stop view"}
					{set "fuel_fire" 1}
					{delay 6 6
						{call "fuel_fire"}
						{components "engine" break}
					}
				}
			else
				{delay 2.5 2.5
					{call "emit_crew"}						;// generic crew emit from vehicle.inc
					{view start "smoke_fuel_1"}
					{set "fuel_fire" 1}
					{components "engine" break}
					{delay 15 5
						;//{spawn "tank_fuel_die" "engine"} does not exist
						{if rand 0.4
							{call "cookoff"}
						}
					}
					{delay 110 20
						{view stop "smoke_fuel_1"}
						{view start "smoke_fuel"}
					}
				}
			}
		}
	}

	{##on "fuel_fire"
		{if rand 0.6
			{delay 7 7
				{call "burn_emit"}
				{call "emit_crew"}						;// generic crew emit from vehicle.inc
				{call "random_fuel_explosion"}
				{if rand 0.5
					{view start "smoke_fuel_1"}
					{delay 15 10 {view start "burn_fire"}}
				else
					{view start "burn_fire"}
					{delay 15 10 {view start "smoke_fuel_1"}}
				}
				{delay 100 20
					{if rand 0.5
						{view stop "smoke_fuel_1"}
						{delay 8 4 {view stop "burn_fire"}}
					else
						{view stop "burn_fire"}
						{delay 8 4 {view stop "smoke_fuel_1"}}
					}
					{view start "smoke_fuel"}
				}
			}
		else
			{delay 73 18
				{view stop "smoke_fuel"}
			}
		}
	}

	{##on "random_fuel_explosion"
		;//{if rand 0.75
			{delay 8 5
				{delay 15 10
					;//{spawn "tank_fuel_die" "engine"} doesn't exist
					;//{components "engine" break}
					;//{damage_report "engine" "component/engine_broken"}
				}
				{if rand 0.4
					{call_synced "ammunition_loads"}
				}
			}
		;//}
	}

	{##on "engine_burn" ;// not called?
		{if not tagged "burned"
			{if not able "exploded"
				{call "stat_break"}
				{view start "smoke_fuel"}
				{delay 3 1
					{add_view "smoke_dead_norm"	"burn_fire"	"FXfire1"}
					{add_view "smoke_black"     "burn_fire" "FXfire1"}
					{view start "burn_fire"}
					{damage_report "engine" "component/engine_burn"}
				}
				{delay 8 1
					{components "engine" break}
					{start_sound "crush/medium/metal"}
					{delay 3
						{call "burn_emit"}
					}
				}
				{delay 14 1
					{if rand 0.75
						{call_synced "cookoff"}
					else
						{view start "smoke3_1"}
						{start_sound "crush/medium/metal"}
						{call "hull_destroyed"}
					}
				}

				{delay 110 20
					{view stop "burn_fire"}
					{view stop "smoke3_1"}
					{view start "smoke_fuel"}
				}
			}
		}
	}

	;/*=========== Fuel Burn/Explosion Chances End ===========*/

	{on "ammo_break"
		{call "stat_break"}
		{if rand 0.4
			{call_synced "explosion"}
		else
			{call_synced "pre_cookoff"}
		}
	}

	{on "kill_cookoff" ;//stops all cookoff delays and sounds
		{kill_delay "cookoff1"}
		{kill_delay "cookoff2"}
		{kill_delay "cookoff3"}
		{kill_delay "cookoff4"}
		{kill_delay "cookoff5"}
		{kill_delay "cookoff6"}
		{kill_delay "cookoff7"}
		{kill_delay "cookoff8"}
		{kill_delay "cookoff9"}
		{tags add "cookoff_killed"}
		{stop_sound "cook_off"}
		{stop_sound "burnup_ammo"}
		{start_sound "detonation/cook_off/transition"}
	}

	(define "cookoff_rand_explosion"
		{delay %0 %1
			{call_synced "kill_cookoff"}
			{call_synced "explosion"}
		}
	)

	{on "pre_cookoff" 		;// Main cookoff decider script (decides which cookoff path is taken)
		{if not tagged "ammo_cooked"
			{call "stat_break"}
			{able minimap 0}
			{able select 0}
			{able repaired 0}
			{tags add "ammo_cooked"}
			{link_sound "cook_off" "detonation/cook_off/cook"}
			{link_sound "cook_off" "detonation/cook_off/transition"}
			{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
			{if rand 0.3 	;//explosion to presmoke cookoff
				{if rand 0.25 ("cookoff_rand_explosion" args 11 11)}  ;//random explosion timer
				{spawn "fire_cooking_explosion" "FXfire3"}
				{start_sound "detonation/he_size1/bkg/"}
				{call "kill_crew_chance"}
				{call "pre_smoke_cookoff"}
				{ani_wind "open" end}
			else rand 0.6	;//presmoke cookoff
				{if rand 0.25 ("cookoff_rand_explosion" args 12 12)}  ;//random explosion timer
				{if rand 0.3	;//delayed presmoke cookoff
					{delay 1 "cookoff1"
						{call "burn_emit"}
						{delay 2 "cookoff2"
							{ani_play "open" +1.0 resume}
							{call "pre_smoke_cookoff"}
						}
					}
				else			;//instant presmoke cookoff
					{call "pre_smoke_cookoff"}
					{ani_wind "open" end}
				}
			else	;//normal cookoff path
				{if rand 0.25 ("cookoff_rand_explosion" args 7 7)} ;//random explosion timer
				{if rand 0.7	;//explosion and slightly delayed normal cookoff
					{spawn "fire_cooking_explosion" "FXfire3"}
					{start_sound "detonation/he_size1/bkg/"}
					{ani_wind "open" end}
					{call "kill_crew_chance"}
					{call "burn_emit"}
					{delay 0.8 0.4 "cookoff3"
						{call "normal_cookoff"}
					}
				else			;//instant normal cookoff
					{call "normal_cookoff"}
				}
			}
		}
	}

	{on "pre_smoke_cookoff"		;// pre-smoke delayed normal cookoff path
		{if not tagged "pre_smoke_cookoff"
			{tags add "pre_smoke_cookoff"}
			{able select 0}
			{view start "cooking_presmoke_1"}
			{delay 3 {call "burn_emit"}}
			{start_sound "detonation/cook_off/internal_explosions"}
			{delay 8 6 "cookoff4"
				{if not able "exploded"
					{view stop "cooking_presmoke_1"}
					{view start "cooking_presmoke_2"}
					{start_sound "detonation/cook_off/internal_explosions"}
					{if rand 0.3
						{view start "cooking_barrel_aftersmoke"}
						{tags add "barrel_fire"}
					}
					{delay 1.5 0.5 "cookoff5"
						{view stop "cooking_presmoke_2"}
						{view start "cooking_presmoke_3"}
						{start_sound "detonation/cook_off/internal_explosions"}
						{delay 0.4 0.2 {start_sound "detonation/cook_off/internal_explosions"}}
						{delay 0.8 0.2 {start_sound "detonation/cook_off/internal_explosions"}}
						{if tagged "barrel_fire"
							{view pause "cooking_barrel_aftersmoke"}
							{view start "cooking_barrel_smoke"}
						}
						{delay 1.5 0.5 "cookoff6"
							{view stop "cooking_presmoke_3"}
							{call "normal_cookoff"}
						}
					}
				}
			}
		}
	}

	{on "normal_cookoff"		;//normal cookoff, instant
		{if not able "exploded"
		{link_sound "hatch_fire" "fire/loops/big"}
			{if rand 0.5
				{spawn "fire_cooking_explosion" "FXfire3"}
				{start_sound "detonation/he_size1/bkg/"}
			}
			{if tagged "barrel_fire"
				{view stop "cooking_barrel_smoke"}
				{view start "cooking_barrel_fire"}
			}
			{fire radius 4 time 4 heating 0.2}
			{kill_crew}
			{clear_inventory}
			{if rand 0.4{view start "cooking_turret_fire"}}
			{view start "cooking_high"}
			{ani_wind "open" end}
			{play_sound "cook_off" 1}
			{play_sound "burnup_ammo" 1}
			{delay 10 2 "cookoff7"
				{view start "cooking_high_2"}
				{view start "cooking_turret_smoke"}
				{view stop "cooking_high"}
				{view stop "cooking_turret_fire"}
				{stop_sound "burnup_ammo"}
				{start_sound "detonation/cook_off/transition"}
				{delay 4 2 "cookoff8"
					{stop_sound "cook_off"}
					{start_sound "detonation/cook_off/transition"}
					{view start "cooking_hatch_fire"}
					{play_sound "hatch_fire" 1}
					{view stop "cooking_high_2"}
					{if tagged "barrel_fire"
						{view start "cooking_barrel_aftersmoke"}
						{view stop "cooking_barrel_fire"}
					}
					{delay 60 10 "cookoff9"
						{view start "cooking_hatch_smoke"}
						{view stop "cooking_hatch_fire"}
						{stop_sound "hatch_fire"}
					}
				}
			}
		}
	}

	{##on "pre_explosion"
		{if tagged "instant_explosion"
			{call "explosion"}
		else
			{if rand 0.35
				{fire radius 4 time 4 heating 0.2}
				{call "stat_break"}
				{damage_report "ammo" "ammo_fire"}
				{link_sound "cook_off" "detonation/cook_off/cook"}
				{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
				{link_sound "fire" "fire/fire"}
				{kill_crew}
				{view start "smoke3_14"} ;//smoke_dead_small2b
				{if rand 0.5
					{view start "smoke3"}	;//fire_cooking_aftersmoke, smoke_dead_norm (open vehicle)
				}
				{delay 1.5 1
					{play_sound "fire" 1}		;//fire/fire
					{if rand 0.33
						{view start "smoke3_8"}	;//fire_cooking_medium_1a
					else rand 0.33
						{view start "smoke3_9"}	;//fire_cooking_medium_1b
					else
						{view start "smoke3_10"} ;//fire_cooking_medium_1c
					}
					{delay 1.5 0.5
						{stop_sound "fire"}
						{play_sound "cook_off" 1} ;//detonation/explosion_vehicle/cook_off/cook_off
						{if rand 0.4
							{delay 0.5 0.5
								{view start "smoke4_1"}	;//fire_cooking_turret_ring
							}
						}
						{view stop "smoke3_8"}	;//fire_cooking_medium_1a
						{view stop "smoke3_9"}	;//fire_cooking_medium_1b
						{view stop "smoke3_10"} ;//fire_cooking_medium_1c
						{view start "smoke3_4"}	;//fire_cooking_explosion_flames
						{delay 1.5 0.5
							{play_sound "burnup_ammo" 1} ;//detonation/explosion_vehicle/cook_off/burnup_ammo
							{view stop "smoke3_4"}	;//fire_cooking_explosion_flames
							{view start "smoke3_11"} ;//fire_cooking_high
							{delay 1.5 0.5
								{stop_sound "cook_off"} ;//detonation/explosion_vehicle/cook_off/cook_off
								{stop_sound "burnup_ammo"} ;//detonation/explosion_vehicle/cook_off/burnup_ammo
								{start_sound "detonation/cook_off/transition"}
								{call "explosion"}
							}
						}
					}
				}
			else
				{call "explosion"}
			}
		}
	}

	{##on "pre_cookoff_call"
		{if rand 0.6
			{if not "turret_teared"
				{call "cookoff"}
			else
				{if tagged "ammo_overload"
					{call "pre_explosion"}
				else
					{call "explosion"}
				}
			}
		else
			{if tagged "ammo_overload"
				{call "pre_explosion"}
			else
				{call "explosion"}
			}
		}
	}

	{##on "cookoff_test"
		{if not tagged "ammo_cooked"
			{tags add "ammo_cooked"}
			{view start "smoke4_1"}
			{view start "smoke_barrel_fire"}
			{view start "smoke3_11"}
			{call "kill_crew_chance"}
			{call "burn_emit"}
		}
	}

	{on "kill_crew_chance"
		{if rand 0.75	{call_synced "kill_driver"}}
		{if rand 0.75	{call_synced "kill_gunner"}}
		{if rand 0.75	{call_synced "kill_gunner2"}}
		{if rand 0.75	{call_synced "kill_gunner3"}}
		{if rand 0.75	{call_synced "kill_charger"}}
		{if rand 0.75	{call_synced "kill_charger2"}}
		{if rand 0.75	{call_synced "kill_charger3"}}
		{if rand 0.75	{call_synced "kill_commander"}}
	}

	{##on "cookoff"
		{if not "ammo_cooked"
			{view start "smoke3_13"}	;//smoke_dead_small2a
			{call "burn_emit"}
			 ;{call "emit_crew"}						;// generic crew emit from vehicle.inc
			{tags add "internal_fire"}
			{if rand 0.2
				{fire radius 5 time 24 heating 0.3}
				{call "engine stop view"}
				{set "ammo_cooked" 1}
				{kill_crew}
				{call "hull_destroyed"}
				{call "stat_break"}
				{view start "smoke4_2"} ;//start high flame FX, turret ring
				{view start "smoke3_8"} ;//start medium flame FX, hatch
				{delay 24
					{view stop "smoke3_8"} ;//stop medium flame FX, hatch
					{view start "smoke4"} ;//start smoke FX, turret ring
				}
			else rand 0.5
				{call "cookoff_hatch"}
				{call "engine stop view"}
			else
				{if rand 0.5
					{view start "smoke3_14"}
				}
				{delay 4 3
					{view start "smoke3_7"}
					{view stop "smoke3_13"}
					{delay 1 0.5
						{view stop "smoke3_7"}
						{call "cookoff_hatch"}
						{call "engine stop view"}
					}
				}
			}
		}
	}

	{##on "cookoff_hatch"
		{if not "ammo_cooked"
			{call "stat_break"}
			{link_sound "cook_off"	"detonation/cook_off/cook"}
			{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
			{link_sound "fire" "fire/fire"}
			{set "ammo_cooked" 1}
			{clear_inventory}
			{kill_crew}
			{damage_report "ammo" "ammo_fire"}
			{able select 0}
			{able repaired 0}
			;{if not work "gun_breech"
				{view start "smoke_barrel"}
				{view start "smoke_barrel_fire"}
			;}
			{if rand 0.5
				{fire radius 4 time 20 heating 0.2}
				{if rand 0.35
					{view start "smoke3_4"}
					{play_sound "cook_off" 1} 					;//start cooking FX, hatch
				else
					{view start "smoke3_11"}
					{play_sound "cook_off" 1}
					{play_sound "burnup_ammo" 1}
				}
				{if rand 0.5
					{view start "smoke3_2"}
					{delay 2
						{view stop "smoke3_2"}
					}
				}
				{if rand 0.3
					{view start "smoke3_6"} 					;//start explosion FX, hatch
					{start_sound "detonation/vehic_die_new"}	;//explosion sound
				}
				{if rand 0.5
					{view start "smoke4_1"} 					;//start cooking FX, turret ring
					{set "turret_flame" 1}
				}
				{delay 8 3
					{view start "smoke3_5"} 					;//start explosion FX, hatch
					{start_sound "detonation/vehic_die_new"}	;//explosion sound
				}
				{delay 15 5
					{view stop "smoke3_4"} 						;//stop cooking FX, hatch
					{view stop "smoke3_11"}
					{view stop "smoke4_1"} 						;//stop cooking FX, turret ring
					{view stop "smoke_barrel_fire"}
					{view start "smoke3_3"} 					;//start after fire FX, hatch
					{if "turret_flame"
						{view stop "smoke4_1"} 					;//stop cooking FX, turret ring
						{view start "smoke4"} 					;//start smoke FX, turret ring
					}
					{stop_sound "burnup_ammo"}
					{stop_sound "cook_off"} 					;//stop cook off sound
					{start_sound "detonation/cook_off/transition"}
					{delay 6 3
						{view start "smoke3_6"}					;//start explosion FX, hatch
						{start_sound "detonation/vehic_die_new"};//explosion sound
					}
					{delay 9
						{view start "smoke3"} 					;//start after smoke FX, hatch
					}
				}
				{delay 250
	  				{view stop "smoke3"} 						;//stop after smoke FX, hatch
					{view start"smoke3_12"} 					;//start slight smoke FX, hatch
				}
			else
				{if rand 0.33
					{view start "smoke3_8"}
				else rand 0.33
					{view start "smoke3_9"}
				else
					{view start "smoke3_10"}
				}
				{fire radius 4 time 30 heating 0.2}
				{play_sound "fire" 1}
				{if rand 0.5
					{view start "smoke3_2"}
					{delay 2 {view stop "smoke3_2"}}
				}
				{if rand 0.5
					{view start "smoke4_1"} 					;//start cooking FX, turret ring
					{set "turret_flame" 1}
				}
				{if rand 0.68
					{delay 10 10
						{call "med-high-cook"}
						{view start "smoke3_5"}
						{start_sound "detonation/vehic_die_new"}
					}
				else
					{delay 30 5
						{stop_sound "fire"}
						{view stop "smoke3_8"}
						{view stop "smoke3_9"}
						{view stop "smoke3_10"}
						{view stop "smoke4_1"} 				;//stop cooking FX, turret ring
						{view stop "smoke_barrel_fire"}
						{view start "smoke3"} 					;//start after smoke FX, hatch
						{if "turret_flame"
							{view stop "smoke4_1"} 			;//stop cooking FX, turret ring
							{view start "smoke4"} 				;//start smoke FX, turret ring
						}
						{delay 6 3
							{view start "smoke3_6"} 				;//start explosion FX, hatch
							;{start_sound "detonation/vehic_die_new"};//explosion sound
						}
					}
					{delay 250
	  					{view stop "smoke3"} 						;//stop after smoke FX, hatch
						{view start"smoke3_12"} 					;//start slight smoke FX, hatch
					}
				}
			}
		}
	}

	{##on "med-high-cook"
		{tags add "med-high-cook"} ;//Ty Test
		{if rand 0.3
			{stop_sound "fire"}
			{call "_explosion"}
		else
			{play_sound "cook_off" 1} 	;//start cooking FX, hatch
			{if rand 0.35
				{view start "smoke3_4"}
			else
				{play_sound "burnup_ammo" 1}
				{view start "smoke3_11"}
			}

			{stop_sound "fire"}
			{view stop "smoke3_8"}
			{view stop "smoke3_9"}
			{view stop "smoke3_10"}
			{if rand 0.5
				{view start "smoke3_2"}
				{delay 2
					{view stop "smoke3_2"}
				}
			}
			{if rand 0.4
				{view start "smoke3_5"}
				{start_sound "detonation/vehic_die_new"}
			}
			{if rand 0.5
				{view start "smoke4_1"} 				;//start cooking FX, turret ring
				{set "turret_flame" 1}
			}
			{if rand 0.4
				{delay 7 3
					{view start "smoke3_5"}
					{start_sound "detonation/vehic_die_new"}
				}
			}
			{delay 12 4
				{view stop "smoke3_4"} 						;//stop cooking FX, hatch
				{view stop "smoke3_11"}
				{view stop "smoke4_1"} 				;//stop cooking FX, turret ring
				{view stop "smoke_barrel_fire"}
				{view start "smoke3_3"} 					;//start after fire FX, hatch
				{if "turret_flame"
					{view stop "smoke4_1"} 			;//stop cooking FX, turret ring
					{view start "smoke4"} 				;//start smoke FX, turret ring
				}
				{stop_sound "burnup_ammo"}
				{stop_sound "cook_off"} 					;//stop cook off sound
				{start_sound "detonation/cook_off/transition"}
				{delay 6 3
					{view start "smoke3_6"} 				;//start explosion FX, hatch
					{start_sound "detonation/vehic_die_new"};//explosion sound
				}
				{delay 9
					{view start "smoke3"} 				;//start after smoke FX, hatch
				}
			}
			{delay 250
				{view stop "smoke3"} 						;//stop after smoke FX, hatch
				{view start"smoke3_12"} 					;//start slight smoke FX, hatch
			}
		}
	}

	(define "ammunition_loads"
		{on "ammunition_loads"
			{if explosive_amount (* %ammo 1.50)		;//>150%
				{if rand 1
					{tags add "instant_explosion"}
					{call "pre_explosion"}
				}
			else explosive_amount (* %ammo 1.25)	;//>125%
				{if rand 0.8
					{tags add "instant_explosion"}
					{call "pre_explosion"}
				}
			else explosive_amount %ammo				;//>100%
				{if rand 0.7
					{tags add "ammo_overload"}
					{call "pre_cookoff_call"}
				}
			else explosive_amount (* %ammo 0.75)	;//>75%
				{if rand 0.6
					{tags add "ammo_normal_load"}
					{call "pre_cookoff_call"}
				}
			else explosive_amount (* %ammo 0.5)		;//>50%
				{if rand 0.5
					{tags add "ammo_normal_load"}
					{call "pre_cookoff_call"}
				}
			else explosive_amount (* %ammo 0.25)	;//>25%
				{if rand 0.4
					{call "pre_cookoff_call"}
				}
			else explosive_amount (* %ammo 0.15)	;//>15%
				{if rand 0
					{call "pre_cookoff_call"}
				}
			else explosive_amount (* %ammo 0)		;//>0%
				{if rand 0
					{call "pre_cookoff_call"}
				}
			}
		}
	)

	;/*===========  End ===========*/

	{on "explosive_amount_tag"		;// tool to determine explosive amount in vehicles when event is called at spawn
		(define "explosive_readout"
			{if explosive_amount %0
				{if not tagged "counted"
					{tags add "explosive_amount_%0"}
					{tags add "counted"}
					{delay 1
						{tags remove "counted"}
					}
				}
			}
		)

		("explosive_readout" args 1700)
		("explosive_readout" args 1690)
		("explosive_readout" args 1680)
		("explosive_readout" args 1670)
		("explosive_readout" args 1660)
		("explosive_readout" args 1650)
		("explosive_readout" args 1640)
		("explosive_readout" args 1630)
		("explosive_readout" args 1620)
		("explosive_readout" args 1610)
		("explosive_readout" args 1600)
		("explosive_readout" args 1500)
		("explosive_readout" args 1400)
		("explosive_readout" args 1300)
		("explosive_readout" args 1200)
		("explosive_readout" args 1100)
		("explosive_readout" args 1000)
		("explosive_readout" args 990)
		("explosive_readout" args 980)
		("explosive_readout" args 970)
		("explosive_readout" args 960)
		("explosive_readout" args 950)
		("explosive_readout" args 940)
		("explosive_readout" args 930)
		("explosive_readout" args 920)
		("explosive_readout" args 910)
		("explosive_readout" args 900)
		("explosive_readout" args 890)
		("explosive_readout" args 880)
		("explosive_readout" args 870)
		("explosive_readout" args 860)
		("explosive_readout" args 850)
		("explosive_readout" args 840)
		("explosive_readout" args 830)
		("explosive_readout" args 820)
		("explosive_readout" args 810)
		("explosive_readout" args 800)
		("explosive_readout" args 790)
		("explosive_readout" args 780)
		("explosive_readout" args 770)
		("explosive_readout" args 760)
		("explosive_readout" args 750)
		("explosive_readout" args 740)
		("explosive_readout" args 730)
		("explosive_readout" args 720)
		("explosive_readout" args 710)
		("explosive_readout" args 700)
		("explosive_readout" args 690)
		("explosive_readout" args 680)
		("explosive_readout" args 670)
		("explosive_readout" args 660)
		("explosive_readout" args 650)
		("explosive_readout" args 640)
		("explosive_readout" args 630)
		("explosive_readout" args 620)
		("explosive_readout" args 610)
		("explosive_readout" args 600)
		("explosive_readout" args 590)
		("explosive_readout" args 580)
		("explosive_readout" args 570)
		("explosive_readout" args 560)
		("explosive_readout" args 550)
		("explosive_readout" args 540)
		("explosive_readout" args 530)
		("explosive_readout" args 520)
		("explosive_readout" args 510)
		("explosive_readout" args 500)
		("explosive_readout" args 490)
		("explosive_readout" args 480)
		("explosive_readout" args 470)
		("explosive_readout" args 460)
		("explosive_readout" args 450)
		("explosive_readout" args 440)
		("explosive_readout" args 430)
		("explosive_readout" args 420)
		("explosive_readout" args 410)
		("explosive_readout" args 400)
		("explosive_readout" args 390)
		("explosive_readout" args 380)
		("explosive_readout" args 370)
		("explosive_readout" args 360)
		("explosive_readout" args 350)
		("explosive_readout" args 340)
		("explosive_readout" args 330)
		("explosive_readout" args 320)
		("explosive_readout" args 310)
		("explosive_readout" args 300)
		("explosive_readout" args 290)
		("explosive_readout" args 280)
		("explosive_readout" args 270)
		("explosive_readout" args 260)
		("explosive_readout" args 250)
		("explosive_readout" args 240)
		("explosive_readout" args 230)
		("explosive_readout" args 220)
		("explosive_readout" args 210)
		("explosive_readout" args 200)
		("explosive_readout" args 190)
		("explosive_readout" args 180)
		("explosive_readout" args 170)
		("explosive_readout" args 160)
		("explosive_readout" args 150)
		("explosive_readout" args 140)
		("explosive_readout" args 130)
		("explosive_readout" args 120)
		("explosive_readout" args 110)
		("explosive_readout" args 100)
		("explosive_readout" args 90)
		("explosive_readout" args 80)
		("explosive_readout" args 70)
		("explosive_readout" args 60)
		("explosive_readout" args 50)
		("explosive_readout" args 40)
		("explosive_readout" args 30)
		("explosive_readout" args 20)
		("explosive_readout" args 10)
		("explosive_readout" args 5)
		("explosive_readout" args 0)
	}
