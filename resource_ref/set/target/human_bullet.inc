{selector
	{unit "human" "bullet"}

	{group
		{ignore {class airborne}}
		{sort	{in_range 10}}
		{sort	{attacking}}
		{sort	{class car_cannon}}
		{sort	{class car_bullet}}
		{sort	{class car}}
		{sort	{class human} {weapon "bullet"}}
		{sort	{class human} {weapon}}
		{sort	{class human}}
		{sort	{threating}}
		{sort	distance}
	}

	{group
		{sort distance}
	}
}