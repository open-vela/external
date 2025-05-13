
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_BT)

  set(ZEPHYR_DIR ${CMAKE_CURRENT_SOURCE_DIR})

  if(CONFIG_ZEPHYR_REPO_3_0_1)
    message("CONFIG_ZEPHYR_REPO_3_0_1")
    include(${ZEPHYR_DIR}/CMakeLists.3_0_1.txt)
  else()
    message("CONFIG_ZEPHYR_REPO_DEFAULT")
    include(${ZEPHYR_DIR}/CMakeLists.default.txt)
  endif()

endif()
