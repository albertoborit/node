'use strict';

const { borit } = internalBinding('borit');

function callBorit() {
  return borit();
}

module.exports = {
  callBorit,
};