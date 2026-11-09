#include <linux/init.h>
#include <linux/errno.h>
#include <linux/kernel.h>

#include "early_detect.h"
#include "cpufreq_limits.h"
#include "debug.h"

static int __init oplus_game_init(void)
{
	int ret;

	ret = early_detect_init();
	if (ret)
		return ret;

	ret = cpufreq_limits_init();
	if (ret) {
		early_detect_exit();
		return ret;
	}

	ret = debug_init();
	if (ret) {
		cpufreq_limits_exit();
		early_detect_exit();
		return ret;
	}

	pr_info("OPLUS game early-detect initialized\n");
	return 0;
}
late_initcall(oplus_game_init);
