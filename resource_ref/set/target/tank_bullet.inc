{selector
 	{type "tank_bullet"}
	
	{group
		{sort {weapon "rocketlauncher ap"} {attacking}}
		{sort {weapon "rocketlauncher ap"} {threating}}
		{sort distance}
	}
	
	{group
		{select {class car_cannon} {weapon}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{sort {class howitzer}}
		{sort {class cannon_zenite}}
		{sort {class cannon_bullet}}
		{sort distance}
	}
	
	{group
		{sort {weapon "at_rifle ap"} {attacking}}
		{sort {weapon "at_rifle ap"} {threating}}
		{sort distance}
	}
	
	{group
		{select {class car_bullet} {weapon}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort distance}
	}
	
	{group
		{sort {class armoredcar}}
		{sort {class cannon_big}}
		{sort {class car}}
		{sort {class airborne}}
		{sort {class airborne}}
		{sort distance}
	}
}
