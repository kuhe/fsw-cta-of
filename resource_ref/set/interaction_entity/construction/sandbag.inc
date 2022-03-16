{"sand sandbag heap"
	{on blast
		{if volume "body"
			{if min_energy 4.7 ;7
				{call "stage2"}
			else min_energy 4 ;0.5
				{if rand 0.25
					{call_synced "stage1"}
				else
					{call_synced "stage2"}
				}
			else min_energy 3 ;0.5
				{if rand 0.6
					{call_synced "stage1"}
				else
					{call_synced "stage2"}
				}
			else min_energy 1.6 ;0.5
				{if rand 0.4
					{call_synced "stage1"}
				else rand 0.4
					{call_synced "stage2"}
				}
			}
		}
	}
	{on break_armor
		 {if volume "body"
		 	{call "stage2"}
		 }
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{if effector "tank"
				{if not "stage1"
					{call "stage1"}
				else rand 0.5
					{delay 0.5
						{call_synced "stage2"}
					}
				}
			else
				{if not effector "cannon"
					{call "stage1"}
				}
			}
		else effector "air_part"
			{if min_speed 5
				{call "stage2"}
			}
		}
	}
	{on bullet_hit
		{if stuff "shell"
			{if stuff "fg"
				{if stuff "big"
					{call "stage2"}
				}
			}
		}
	}
	{on "stage1"
		{if not "stage1"
			{set "stage1" 1}
;//			{volumes disable contact}
			{call "change_model"}
			{delay 0.01
				{volumes enable contact visible}
			}
			{delay 0.1
				{bone show "x1"}
				{bone hide "x2"}
				{ani_play "crush1"}
				{delay 0.1
					{update_visibility_patch}
				}
			}
		}
	}
	{on "stage2"
		{if not "stage2"
			{set "stage1" 1}
			{set "stage2" 1}
			{call "change_model"}
			{tags add "crushed"}
			{delay_ex 0.1
				{bone hide "x1"}
				{bone show "x2"}
				{ani_play "crush2" 1}
				{volumes "body" disable bullet contact blast visible touch}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{delay_ex 0.1
					{call "cut_pieces"}
				}
				{delay 0.3
					{update_visibility_patch}
					{area disable}
				}
				{land off}
			}
		}
	}
	{on "change_model"
		{if not "sliced"
			{set "sliced" 1}
			{delay 0
				{set_skeleton "_x"}
				{volumes disable contact visible}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{volumes enable contact}
				{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				{if rand 0.3
					{add_view "dust_small" "dust" "root"}
					{view start "dust"}
					{delay_effect 2 1 "stop"}
				}
			}
		)
		("cut_pieces")
	}
}

{"sandbag no_stage"  ;// temp fix for sandbags. Need to find better final solution.
	{on blast overload
		{if volume "body"
			{if min_energy 4.7 ;7
				{call "stage2"}
			else min_energy 4 ;0.5
				{call "stage2"}
			else min_energy 3 ;0.5
				{call "stage2"}
			else min_energy 1.6 ;0.5
				{call "stage2"}
			}
		}
	}
	{on "change_model" overload
		{if not "sliced"
			{set "sliced" 1}
			{delay 0
				{set_skeleton "_x"}
				{volumes disable contact visible}
				{if "stage2"
					{call "cut_pieces"}
				else
					{call "cut_subpieces"}
				}
			}
		}
	}
	{on "cut_subpieces"
		(define "cut_subpiece"
			{tear "piece_medium_sand" bone "piece%0"
				{volumes enable contact}
				{impulse up -0.1 dir 1 2 no_position}
				{if rand 0.3
					{add_view "dust_small" "dust" "root"}
					{view start "dust"}
					{delay_effect 2 1 "stop"}
				}
			}
		)
		("cut_subpieces")
	}
}

{"sandbag_round"
	{on blast overload
		{if volume "body"
			{if min_energy 5 ;7
				{call "stage2"}
			else min_energy 4 ;0.5
				{if rand 0.5
					{call_synced "stage1"}
				else rand 0.5
					{call_synced "stage2"}
				}
			else min_energy 3 ;0.5
				{if rand 0.5
					{call_synced "stage1"}
				else rand 0.4
					{call_synced "stage2"}
				}
			else min_energy 1.6 ;0.5
				{if rand 0.3
					{call_synced "stage1"}
				else rand 0.4
					{call_synced "stage2"}
				}
			}
		}
	}
}

{"sandbag onestage"  ;// New sandbags with FX bones to spawn extra stuff. 
	{on blast
		{if volume "body"
			{if min_energy 4.7 ;7
				{call "stage2"}
			else min_energy 4 ;0.5
				{if rand 0.25
					{call_synced "stage1"}
				else
					{call_synced "stage2"}
				}
			else min_energy 3 ;0.5
				{if rand 0.6
					{call_synced "stage1"}
				else
					{call_synced "stage2"}
				}
			else min_energy 1.6 ;0.5
				{if rand 0.4
					{call_synced "stage1"}
				else rand 0.4
					{call_synced "stage2"}
				}
			}
		}
	}
	{on break_armor
		 {if volume "body"
		 	{call "stage2"}
		 }
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{if effector "tank"
				{if not "stage1"
					{delay 0
						{call "stage1"}
					}
					{delay 1
						{volumes enable contact visible}
					}
				else 
					{delay 0
						{call "stage2"}
					}
				}
			else
				{if not effector "cannon"
					{delay 0
						{call "stage1"}
					}
					{delay 0.01
						{volumes enable contact visible}
					}
				}
			}
		else effector "air_part"
			{if min_speed 5
				{call "stage2"}
			}
		}
	}
	{on bullet_hit
		{if stuff "shell"
			{if stuff "fg"
				{if stuff "big"
					{call "stage2"}
				}
			}
		}
	}
	{on "stage1"
		{if not "stage1"
			{set "stage1" 1}
			{call "sandbag_crush_fx"}
		}
	}
	{on "stage2"
		{if not "stage2"
			{set "stage1" 1}
			{set "stage2" 1}
			;{call "destroyed_stamp"}
			;{call "sandbag_crush_fx"}
			{if not "sliced"
				{set "sliced" 1}
				{delay 0
					{set_skeleton "_x"}
					{volumes disable contact visible}
					{if tagged "crushed"
						{call "cut_pieces_noblast"}
					else
						{call "cut_pieces"}
					}
				}
			}
			{delay 1
				{tags add "crushed"}
			}
		}
	}
	{on "cut_pieces_noblast"
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{volumes enable contact}
				{impulse up 0.25 0.25 dir 0.25 0.25 rnd_dir 2 no_position}
				{if rand 1
					{add_view "dust_small" "dust" "root"}
					{view start "dust"}
					{delay_effect 2 1 "stop"}
				}
			}
		)
		("cut_pieces")
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 1.4 dir 3.5 2.5 rnd_dir 5 no_position}
				{if rand 1
					{add_view "dust_small" "dust" "root"}
					{view start "dust"}
					{delay_effect 2 1 "stop"}
				}
			}
		)
		("cut_pieces")
	}
	{on "destroyed_stamp" overload
		{spawn "destroy_sand"	no_position	}
	}
}

{"sandbag onestage small"
	{on "sandbag_crush_fx"
	; do nothing
	}
}

{"sandbag onestage jettison_sandbags1"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag1"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag1"}
		else terrain_fx "sand"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "tank_fire_zenite_dust_sand" "fx_sandbag1"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "tank_fire_zenite_dust_ground" "fx_sandbag1"}
		}
	}
}

{"sandbag onestage jettison_sandbags2"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag2"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag2"}
		else terrain_fx "sand"
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "tank_fire_zenite_dust_sand" "fx_sandbag2"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "tank_fire_zenite_dust_ground" "fx_sandbag2"}
		}
	}
}

{"sandbag onestage jettison_sandbags3"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"	
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag2"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag2"}
		else terrain_fx "sand"
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "tank_fire_zenite_dust_sand" "fx_sandbag2"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "tank_fire_zenite_dust_ground" "fx_sandbag2"}
		}
	}
}

{"sandbag onestage jettison_sandbags4"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "sandbag_crush_win" "fx_sandbag4"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag2"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "sandbag_crush_win" "fx_sandbag4"}
			{spawn "tank_fire_zenite_dust_snow" "fx_sandbag2"}
		else terrain_fx "sand"
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "sandbag_crush" "fx_sandbag4"}
			{spawn "tank_fire_zenite_dust_sand" "fx_sandbag2"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "sandbag_crush" "fx_sandbag4"}
			{spawn "tank_fire_zenite_dust_ground" "fx_sandbag2"}
		}
	}
}