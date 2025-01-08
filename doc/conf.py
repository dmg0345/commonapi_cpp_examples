"""
Configuration file for the Sphinx documentation builder, this file expects Doxygen to have been executed first and
its XML output to be at the specified location. Relevant links for documentation of Sphinx and Doxygen are shown below:

  - Sphinx:
    - https://www.sphinx-doc.org/en/master/usage/configuration.html
    - Conditional Documentation: https://stackoverflow.com/a/45637280/21951997
  - Breathe:
    - Summary of all directives: https://breathe.readthedocs.io/en/latest/directives.html
  - Doxygen:
    - Grouping: https://www.doxygen.nl/manual/grouping.html
    - Autolink to enumerations, functions and so on: https://www.doxygen.nl/manual/autolink.html
    - Conditional documentation: https://www.doxygen.nl/manual/commands.html#cmdif
"""

# pylint: skip-file
# type: ignore

import sphinx
import subprocess
import os
import docutils
import xml.etree.ElementTree as ET

## Project information #################################################################################################
# Project name.
project = "commonapi_cpp_examples"
# Friendly name.
friendly_name = "CommonAPI C++ Examples"
# Project author.
author = "Diego Martínez García <dmg0345@gmail.com>"
# Project copyright.
copyright = author
# Project version.
version = "0.0.3"
# Project release, set it as the same value as version as the separation is not required.
release = version

## Sphinx General configuration ########################################################################################
# Sphinx and custom extensions.
extensions = [
    # Read The Docs theme extension:
    #    - https://github.com/readthedocs/sphinx_rtd_theme
    #    - https://sphinx-rtd-theme.readthedocs.io/en/stable/
    "sphinx_rtd_theme",
    # Breathe extension:
    #    - https://github.com/breathe-doc/breathe
    #    - https://breathe.readthedocs.io/en/latest/
    #    - https://www.doxygen.nl/manual
    "breathe"
]
# File extensions of source files.
source_suffix = {".rst": "restructuredtext"}
# Encoding of reST files.
source_encoding = "utf-8-sig"
# Root document.
root_doc = "index"
# Glob-style patterns to exclude when looking for source files.
exclude_patterns = [".sphinx_build", ".doxygen_build"]
# Included at the end of every RestructuredText source file that is read.
rst_epilog = f""""""
# Included at the beginning of every RestructuredText source file that is read.
rst_prolog = f"""
.. |ProjectName| replace:: **{project}**
.. |ProjectFriendlyName| replace:: **{friendly_name}**
.. |ProjectCopyright| replace:: **{copyright}**
.. |ProjectVersion| replace:: **{version}**
"""
# Enable nitpicky mode.
nitpicky = True
# Unset pygments style so that the one of the default theme is used for highlighting.
pygments_style = None
# Keep module names hidden in the documentation as that results in too verbose documentation.
add_module_names = False
# Do not add objects such as classes, functions or methods as part of the TOC.
toc_object_entries = False

## Sphinx Internalization configuration ################################################################################
# Set language to english.
language = "en"

## Sphinx HTML output configuration ####################################################################################
# The theme to use.
html_theme = "sphinx_rtd_theme"
# Specific options for the theme.
html_theme_options = {
    "logo_only": False,
    "display_version": True,
    "style_external_links": False,
    "collapse_navigation": False,
    "includehidden": True,
    "navigation_depth": 4,
}
# HTML title.
html_title = f"{friendly_name} v{version}"
# HTML short title.
html_short_title = html_title
# HTML base URL which points to the root HTML documentation.
html_baseurl = ""
# Path to the HTML logo.
html_logo = None
# Path to the HTML fav icon.
html_favicon = None
# Paths to static files and folders, will be stored in '_static' folder.
html_static_path = [
    "../other/commonapi_docs/FrancaUserGuide-0.12.0.1.pdf",
    "../other/commonapi_docs/CommonAPICppSpecification.pdf",
    "../other/commonapi_docs/CommonAPICppUserGuide.pdf",
    "../other/commonapi_docs/CommonAPI-4_deployment_spec.fdepl",
    "../other/commonapi_docs/dbus/CommonAPI-4-DBus_deployment_spec.fdepl",
    "../other/commonapi_docs/dbus/CommonAPIDBusCppUserGuide.pdf",
    "../other/commonapi_docs/someip/CommonAPI-4-SOMEIP_deployment_spec.fdepl",
    "../other/commonapi_docs/someip/CommonAPISomeIPCppUserGuide.pdf",
    "../other/commonapi_docs/someip/vsomeipUserGuide.html"
]
# Add permalinks to every section.
html_permalinks = True
# Do not include the original sources in the final documentation.
html_copy_source = False
# Do not include links to the sources in the documentation.
html_show_sourcelink = False
# Show copyright in the HTML footer.
html_show_copyright = True
# Disable created by Sphinx text in the HTML footer.
html_show_sphinx = False
# Set the language for the search to english.
html_search_language = "en"

## Breathe Extension configuration #####################################################################################
# Set list of projects and their paths to the XML doxygen files.
breathe_projects = {
    "all": ".doxygen_build/xml"
}
# Set the default project from the projects listed above.
breathe_default_project = "all"
# Set domains by extension for C and C++ separately.
breathe_domain_by_extension = {
    "h": "c",
    "c": "c",
    "hpp": "cpp",
    "cpp": "cpp"
}
# For defines, do not show their values in the documentation.
breathe_show_define_initializer = False
# For enumeration values, do not show their values in the documentation.
breathe_show_enumvalue_initializer = False
# Do not show includes in the documentation.
breathe_show_include = False
# Debug directives.
breathe_debug_trace_directives = True

## Setup functionality #################################################################################################
def run_doxygen() -> None:
    """Runs doxygen as part of the Sphinx workflow, without rebuilding unless necessary."""
    # Set paths to relevant files.
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    dexe = "doxygen"
    cdir = os.path.join(root, "doc")
    cmdir = os.path.join(root, ".cmake_build")

    # Build command, ensuring the Python virtual environmnet is activated.
    cmd = "pwsh -Command '"
    cmd += f'& "$ENV:VIRTUAL_ENV_PATH/bin/Activate.ps1";'
    cmd += f'& "{os.path.join(root, "manage.ps1")}" load;'
    cmd += f'Start-Doxygen -DoxygenExe "{dexe}" -ConfigFolder "{cdir}" -CMakeBuildDir "{cmdir}" -NoRebuild;'
    cmd += "'"

    # Run command and check for errors.
    res = subprocess.run(cmd, shell=True, cwd=root, encoding="utf8", text=True, capture_output=True)
    print(res.stdout)
    if res.returncode != 0:
        raise sphinx.errors.ConfigError(f"Call to Doxygen finished with error '{res.returncode}'...")

def breathe_load_tags_on_doxyfile() -> None:
    """Loads the ENABLED_SECTIONS configuration of the DoxyFile when the XML is generated, and adds it as tags, suitable
    to be used with the @only directive in Sphinx.

    Note that only sections with valid Python identifiers are loaded: Only contains alphanumeric letters (a-z) and
    (0-9), or underscores (_). A valid identifier cannot start with a number, or contain any spaces."""
    # Create path to the file and ensure it exists.
    doxyfile_xml = os.path.join(os.path.dirname(os.path.abspath(__file__)), ".doxygen_build", "xml", "Doxyfile.xml")
    if not os.path.exists(doxyfile_xml):
        raise sphinx.errors.ConfigError(f"Could not find Doxyfile at '{doxyfile_xml}'...")
    # Parse XML and get the ENABLED_SECTIONS values, if they exist.
    elems = [elem for elem in ET.parse(doxyfile_xml).getroot() if elem.get("id", "") == "ENABLED_SECTIONS"]
    if len(elems) > 1:
        raise sphinx.errors.ConfigError(f"Multiple 'ENABLED_SECTIONS' XML elements found, check the Doxyfile.")
    # Add all tags with valid Python identifiers.
    if len(elems) == 1:
        _ = [tags.add(tag.text) for tag in elems[0] if tag.text.isidentifier()]

def on_missing_reference(app: sphinx.application.Sphinx,
                         env: sphinx.environment.BuildEnvironment,
                         node: sphinx.addnodes.pending_xref,
                         contnode: docutils.nodes.TextElement) -> docutils.nodes.reference | None:
    """Handler for 'missing-reference' warning. Lots of false positives can be raised by Sphinx from this, for
    example from missing references to standard library types or missing references to third-party types that are not
    documented by Sphinx or which are not processed by Doxygen.

    One solution is to disable errors as warnings, but this is not convenient as it could hide real errors. Another
    solution implies the use of 'c_extra_keywords' and 'c_id_attributes', however, this also causes other kind of
    errors. Thus the solution to handle the event directly.

    The implementation of this handler allows to ignore this kind of warnings and also to look for substitue
    nodes when a reference has not been found."""
    # Print missing reference in color in the terminal to differentiate it.
    print(f"\033[93m on_missing_reference: {node}.\033[00m")

    # The lookup dictionary with missing targets and replacements.
    reftargets = {
        "c": {

        },
        "cpp": {
            "*": {
                "size_t": None, "uint32_t": None,
                "CommonAPI": None, "CommonAPI::Runtime": None, "CommonAPI::ClientId": None,
                "v0_1": None, "v0_1::commonapi": None, "v0_1::commonapi::app": None, "v0_1::commonapi::app::AppStubDefault": None,
                "v0_1::commonapi::app::AppProxy": None,
            },
            "app/client": {
                "Utils::Capi::Priv": None, "Proxy": None, "AttributeExtensions": None
            },
            "app/server": {
                "Utils::Capi::Priv": None, "Stub": None, "pingReply_t": None,
            },
            "utils/capi": {
                "Priv": None
            }
        }
    }

    # Obtain the reference target replacement, if any, note that refdoc replacements take priority over global ones.
    domain_dict = reftargets.get(node["refdomain"], {})
    reftarget = {**domain_dict.get("*", {}), **domain_dict.get(node["refdoc"], {})}.get(node["reftarget"], False)

    # Check if the replacement target has been found and the node refers to an identifier.
    if all([node["reftype"] == "identifier", reftarget is not False]):
        # No explicit replacement for target, thus acknowledge warning and continue with node as is.
        if reftarget is None:
            return contnode

        # Find explicit replacement for target, and ensure there is no ambiguity.
        reftarget_cand = env.domains[node["refdomain"]].resolve_any_xref(
            env, './index', app.builder, reftarget, node, contnode
        )
        if len(reftarget_cand) != 1:
            raise sphinx.errors.ExtensionError(f"Found {len(reftarget_cand)} '{reftarget}' replacements for '{node['reftarget']}'.")
        return reftarget_cand[0][1]

    # Could not resolve identifier, let other handlers resolve it if they can.
    return None

def setup(app: sphinx.application.Sphinx):
    """Setup function for Sphinx, refer to the links below for details:

        - https://www.sphinx-doc.org/en/master/extdev/appapi.html#module-sphinx.application
        - https://www.sphinx-doc.org/en/master/extdev/appapi.html#sphinx-core-events"""
    # If the 'DOXYGEN_DISABLED' tag was provided, then do not include doxygen in the Sphinx workflow.
    if "DOXYGEN_DISABLED" not in tags:
        # Call doxygen to build the XML.
        run_doxygen()
    # Load relevant tags to the 'tags' object from the Doxyfile.
    breathe_load_tags_on_doxyfile()
    # Register handler for the 'missing-reference' event.
    app.connect("missing-reference", on_missing_reference)
    # Print tags just for informational purpopses.
    print(f"Tags: {[i for i in tags]}.")
