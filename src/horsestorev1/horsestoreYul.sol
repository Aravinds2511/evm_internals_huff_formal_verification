// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

contract HorseStoreYul {
    uint256 numberOfHorses;

    function updateHorseNumber(uint256 newNumberOfHorses) external {
        // numberOfHorses = newNumberOfHorses;
        assembly {
            sstore(numberOfHorses.slot, newNumberOfHorses)
        }
    }

    function readNumberOfHorses() external view returns (uint256) {
        // return numberOfHorses;
        assembly {
            let x:= sload(numberOfHorses.slot)
            mstore(0, x)
            return(0, 0x20)
        }
    }
}
