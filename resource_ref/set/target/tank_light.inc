{selector
	{type "tank_light"}
	
	{group
		{select {class armoredcar}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{select {class tank_light}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{ignore {class airborne}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort distance}
	}
	{group
		{select {class car_cannon} {weapon}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class tank_medium}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class tank_heavy}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{sort {weapon "rocketlauncher ap"} {attacking}}
		{sort {weapon "rocketlauncher ap"} {threating}}
		{sort distance}
	}
	{group
		{sort {weapon "at_rifle ap"} {attacking}}
		{sort {weapon "at_rifle ap"} {threating}}
		{sort distance}
	}
	{group
		{sort {class tank_bullet}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class car_bullet} {weapon}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{select {class car}}
		{sort distance}
	}
	{group
		{sort {attacking}}
		{sort distance}
	}
}