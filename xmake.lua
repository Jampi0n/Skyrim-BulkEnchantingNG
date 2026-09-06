-- include subprojects
includes(os.getenv("COMMONLIB_SSE_FOLDER"))


-- set project constants
set_project("BulkEnchantingRedone")
set_version("1.3.0")
set_license("GPL-3.0")
set_languages("c++23")
set_warnings("allextra")


add_defines("NOMINMAX")

-- add common rules
add_rules("mode.debug", "mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- define targets
target("BulkEnchantingRedone")
add_rules("commonlibsse-ng.plugin", {
    name = "BulkEnchantingRedone",
    author = "Jampion",
    description = "BulkEnchantingRedone"
})

-- add src files
add_files("src/**.cpp")
add_headerfiles("src/**.h")
add_includedirs("src")
set_pcxxheader("src/pch.h")
